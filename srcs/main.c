/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/09 14:35:18 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rtv1.h>
#include <unistd.h>
#include <libft.h>
#include <math.h>
#include <stdio.h>

t_point			matrice_sum_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x + matrice2.x;
	result.y = matrice1.y + matrice2.y;
	result.z = matrice1.z + matrice2.z;
	return (result);
}

t_point			matrice_sub_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x - matrice2.x;
	result.y = matrice1.y - matrice2.y;
	result.z = matrice1.z - matrice2.z;
	return (result);
}

double			matrice_mult_1x1(t_point matrice1, t_point matrice2)
{
	double		result;
	result = matrice1.x * matrice2.x;
	result += matrice1.y * matrice2.y;
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
	ray->pos.z = -1000;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 1;

	//ray direction normalized
}

void				set_sphere(t_object **object)
{
	t_sphere *sphere;

	*object = (t_object *)malloc(sizeof(t_object));
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->pos.x = 240;
	sphere->pos.y = 240;
	sphere->pos.z = 0;
	sphere->radius = 240;
	(*object)->type = SPHERE;
	(*object)->ptr = sphere;
}

void				normalized(t_point *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}

t_bool				touch_sphere(t_object *object,t_ray ray, double *t)
{
	double		b;
	double		delta;
	double		t0;
	double		t1;
	t_sphere	*sphere;
	t_point		dist;

	sphere = (t_sphere *)object->ptr;
	dist = matrice_sub_1x1(sphere->pos, ray.pos);
	b = matrice_mult_1x1(ray.dir, dist);
	delta = ((b * b) - matrice_mult_1x1(dist, dist) + (sphere->radius * sphere->radius));
	t0 = b - sqrt(delta);
	t1 = b + sqrt(delta);
	if (t0 > 0.1f && t0 < *t)
		*t = t0;
	else if (t1 > 0.1f && t1 < *t)
		*t = t1;
	else
		return (FALSE);
	printf("t0 = %f, t1 = %f, delta = %f, b = %f, t = %f\n", t0, t1, delta, b, *t);
	return (TRUE);
}

void				trace_sphere(t_object *object, t_env env)
{
	t_ray		ray;
	int			*img;
	int			i;
	int			j;
	double		t;

	i = 0;
	j = 0;
	t = 1200;
	ray = env.ray;
	normalized(&ray.dir);
	img = (int *)env.img_addr;
	while (j < HEIGHT)
	{
		i = 0;
		ray.pos.y = j;
		ray.pos.x = i;
		while (i < WIDTH)
		{
			if (touch_sphere(object, ray, &t))
				*(img + i + (env.size_line * j) / 4) = GREEN;// - BLUE/ ((t0 > 0) ? t0 : -t0);
			i++;
			ray.pos.x = i;
		}
		j++;
	}
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
