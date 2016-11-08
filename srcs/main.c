/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/08 16:51:47 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rtv1.h>
#include <unistd.h>
#include <libft.h>
#include <math.h>
#include <stdio.h>

/*
   void				set_segment(t_segment *segment)
   {
   segment->posx = 100;
   segment->posy = 80;
   segment->posz = 0;
   segment->y = 80;
   segment->x = 350;
   if (segment->y != segment->posy)
   segment->pente = (segment->x - segment->posx) / (segment->y - segment->posy);
   else
   segment->pente = 0;
   }

   static void				trace_segment(t_mlx *ptr, t_segment segment)
   {
   double	xs;
   double	ys;
   double	xe;
   double	ye;
   int		*img;

   xs = segment.posx;
   ys = segment.posy;
   xe = segment.x;
   ye = segment.y;
   img = (int *)ptr->img_addr + ((int)ys * (ptr->size_line / 4));
   while (ys <= WIDTH && ys <= ye)
   {
   xs = segment.posx;
   while (xs <= WIDTH && xs <= xe)
   {
   if (ye != ys && ((xs - segment.posx) / (ys - segment.posy)) == segment.pente)
 *(img + (int)xs) = GREEN;
 else if (ye == ys && segment.pente == 0)
 *(img + (int)xs) = RED;
 xs++;
 }
 img += (ptr->size_line / 4);
 ys++;
 }
 }

 void				set_rectangle(t_rectangle *rectangle)
 {
 rectangle->posx = 100;
 rectangle->posy = 100;
 rectangle->posz = 0;
 rectangle->length = 50;
 rectangle->width = 100;
 }

 static void				trace_rectangle(t_mlx *ptr, t_rectangle rectangle)
 {
 double	xs;
 double	ys;
 double	xe;
 double	ye;
 int		*img;

 xs = rectangle.posx;
 ys = rectangle.posy;
 xe = xs + rectangle.width;
 ye = ys + rectangle.length;
 img = (int *)ptr->img_addr + ((int)ys * (ptr->size_line / 4));
 while (ys <= WIDTH && ys <= ye)
 {
 xs = rectangle.posx;
 while (xs <= WIDTH && xs <= xe)
 {
 *(img + (int)xs) = BLUE;
xs++;
}
img += (ptr->size_line / 4);
ys++;
}
}
void				set_square(t_square *square)
{
	square->posx = 300;
	square->posy = 100;
	square->posz = 0;
	square->width = 50;
}

static void				trace_square(t_mlx *ptr, t_square square)
{
	double	xs;
	double	ys;
	double	xe;
	double	ye;
	int		*img;

	xs = square.posx;
	ys = square.posy;
	xe = xs + square.width;
	ye = ys + square.width;
	img = (int*)ptr->img_addr + ((int)ys * (ptr->size_line/ 4));
	while (ys <= WIDTH && ys <= ye)
	{
		xs = square.posx;
		while (xs <= WIDTH && xs <= xe)
		{
			*(img + ((int)xs)) = WHITE;
			xs++;
		}
		img += (ptr->size_line / 4);
		ys++;
	}
}
*/

t_point			matrice_sum_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x + matrice2.x;
	result.y = matrice1.y + matrice2.z;
	result.z = matrice1.z + matrice2.z;
	return (result);
}

t_point			matrice_sub_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x - matrice2.x;
	result.y = matrice1.y - matrice2.z;
	result.z = matrice1.z - matrice2.z;
	return (result);
}

double			matrice_mult_1x1(t_point matrice1, t_point matrice2)
{
	double		result;
	result = matrice1.x * matrice2.x;
	result += matrice1.y * matrice2.z;
	result += matrice1.z * matrice2.z;
	return (result);
}

int					ft_exit(int keycode)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(2);
	return (1);
}
void				set_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->pos.z = 1;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = -1000;
	//ray direction normalized
}

void				set_sphere(t_object **object)
{
	t_sphere *sphere;

	*object = (t_object *)malloc(sizeof(t_object));
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 0;
	sphere->radius = 10;
	(*object)->type = SPHERE;
	(*object)->ptr = sphere;
}

void				trace_sphere(t_object *object, t_env env)
{
	double		b;
	double		delta;
	double		t0;
	double		t1;
	t_point		dist;
	t_ray		ray;
	t_sphere	*sphere;
	int			*img;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ray = env.ray;
	sphere = (t_sphere *)object->ptr;
	img = (int *)env.img_addr;
	while (j < HEIGHT)
	{
		i = 0;
		ray.pos.y = j;
		ray.pos.x = 0;
		while (i < WIDTH)
		{
			dist = matrice_sub_1x1(sphere->pos, ray.pos);
			b = matrice_mult_1x1(ray.dir, dist);
			delta = ((b * b) - matrice_mult_1x1(dist, dist) + (sphere->radius * sphere->radius));
			t0 = b - sqrt(delta);
			t1 = b + sqrt(delta);
			printf("delta = %f, b = %f\n", delta, b);
			printf("t0 = %f, t1 = %f\n", t0, t1);
			if (t0 > 0.0f || t1 > 0.0f)
			
			if (j < HEIGHT &&  i < WIDTH)
				*(img + i + (env.size_line * j) / 4) = GREEN;
			i++;
			ray.pos.x = i;
		}
		j++;
	}
	/*	a = (ray.dirx * ray.dirx) +  (ray.diry * ray.diry) + (ray.dirz * ray.dirz);
		b = 2 * (ray.dirx * (ray.x - sphere.x) + ray.diry * (ray.y - sphere.y) +
		ray.dirz * (ray.z - sphere.z));
		c = ((ray.x - sphere.x) * (ray.x - sphere.x) + (ray.y - sphere.y)) * (ray.y - sphere.y) + (ray.z - sphere.z) * (ray.z - sphere.z))  sphere.radius * sphere.radius;

		delta = b * b - (4 * a * c);
		if (delta == 0)
		{

		}
		else if (delta > 0)
		*/
}

int					main(void)
{
	t_env		env;

	env.bpp = 0;
	env.size_line = 0;
	env.endian = 0;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "hello");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img_addr = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);

	set_ray(&env.ray);
	set_sphere(&env.object);
	trace_sphere(env.object, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	write(1, "finish", 6);
	mlx_hook(env.win, 2, (1L<<0), ft_exit, &env);
	mlx_hook(env.win, 17, (1L<<17), ft_exit, &env);
	mlx_loop(env.mlx);
	return (0);
}
