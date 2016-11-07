/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/07 18:39:53 by lgatibel         ###   ########.fr       */
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
void				set_ray(t_ray ray)
{
	ray.x = 0;
	ray.y = 0;
	ray.z = 0;
	ray.dirx = 0;
	ray.diry = 0;
	ray.dirz = 10;
}

void				set_sphere(t_object *object)
{
	object->ptr = (t_sphere *)malloc(sizeof(t_sphere));
	object.pos.x = 0;
	object.pos.y = 0;
	object.pos.z = 0;
	object->radius = 10;
	object->type = SPHERE;
}

void				trace_sphere(t_object *object, t_env env)
{
	double		a;
	double		b;
	double		c;
	t_point		sphere;
	t_ray		ray;
	float		delta;

	sphere = object.pos;
	ray = ray.ray;
	a = (ray.dirx * ray.dirx) +  (ray.diry * ray.diry) + (ray.dirz * ray.dirz);
	b = 2 * (ray.dirx * (ray.x - sphere.x) + ray.diry * (ray.y - sphere.y) +
			ray.dirz * (ray.z - sphere.z));
	c = ((ray.x - sphere.x) * (ray.x - sphere.x) + (ray.y - sphere.y)) * (ray.y - sphere.y) + (ray.z - sphere.z) * (ray.z - sphere.z))  sphere.radius * sphere.radius;

	delta = b * b - (4 * a * c);
	if (delta == 0)
	{
		
	}
	else if (delta > 0)

void				trace_sphere(t_mlx *ptr, t_sphere sphere)
{

}

int					main(void)
{
	t_env		env;

/*	

*/
	env.bpp = 0;
	env.size_line = 0;
	env.endian = 0;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "hello");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img_addr = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
/*
	set_segment(&segment);
	set_square(&square);
	set_rectangle(&rectangle);
	trace_segment(&ptr, segment);
	trace_square(&ptr, square);
	trace_rectangle(&ptr, rectangle);
*/
	set_ray(env.ray);
	set_sphere(env.object);
	trace_sphere(env.object, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	write(1, "finish", 6);
	mlx_loop(env.mlx);
	return (0);
}
