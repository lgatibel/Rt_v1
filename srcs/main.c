/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/22 11:10:58 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				reverse_tp3d(t_p3d *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}

double		norm(t_p3d *vec)
{
	double res;
	res = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	return (res);
}

double				length_ray(t_ray *ray, double t, t_p3d *intersect)
{
	if (t <= 0)
		return (-8);
	cpy_tp3d(intersect, mult_nb_tp3d(sum_tp3d(ray->pos, ray->dir), t));
	return (norm(intersect));
}

t_object			*calc_object(t_object *object, t_p3d *intersect, t_ray *ray)
{
	double		t;
	t_object	*nearest;

	t = -1;
	nearest = NULL;
	int i = 0;
	while (object)
	{
		i++;
		if (object->type == SPHERE)
			t = calc_sphere(object, ray);
		else if (object->type == CYLINDER)
			t = calc_cylinder(object, ray);
		else if (object->type == CONE)
			t  = calc_cone(object, ray);
		else if (object->type == PLANE)
			t = calc_plane(object, ray);
		object->dist = length_ray(ray, t, intersect);
		if (object->dist > 0 && ((!nearest) || (object->dist < nearest->dist)))
			nearest = object;
		object = object->next;
	}
	return (nearest);
}

t_p3d				calc_norm(t_p3d *intersect, t_object *nearest_object)
{
	if (nearest_object->type == SPHERE)
		return(calc_sphere_norm(intersect, nearest_object));
	else if (nearest_object->type == CYLINDER)
		return (calc_cylinder_norm(intersect, nearest_object));
	else if (nearest_object->type == CONE)
		return (calc_cone_norm(nearest_object));
	else if (nearest_object->type == PLANE)
		return (calc_plane_norm(nearest_object));
	set_tp3d(&nearest_object->norm, -8, -8, -8);
	return (nearest_object->norm);
}

int					calc_light(t_env *env)
{
	t_ray		*light;
	double		angle;
	double		diffuse;
	int			col;
	t_object	*nearest;

	nearest = NULL;
	light = &env->light;
	light->dir = sub_tp3d(env->intersect, light->pos);
	nearest = calc_object(env->object, &env->light_intersect, light);
	if (!nearest || env->nearest_object->ptr != nearest->ptr)
		return (YELLOW);//env->font_color);
/*
	if (nearest->type == SPHERE)
		return (GREEN);
	else
		return (RED);
*/
	env->color = nearest->color;
//		printf("nearest[%p], nearest[%p]\n",env->nearest_object->ptr, nearest->ptr);
	reverse_tp3d(&light->dir);
	normalized(&light->dir);
	angle = mult_tp3d(calc_norm(&env->intersect, nearest),
			light->dir);
	diffuse = (angle < 1) ? angle * COEFF : 0;
	col = ((int)(color(env->color, RED) * diffuse) << 16) +
	((int)(color(env->color, GREEN) * diffuse) << 8) +
	(int)(color(env->color, BLUE) * diffuse);
//	return (col);
	return ((col > 0) ? col : env->font_color);
}

void				trace(t_env *env)
{
	int		x;
	int		y;
	int		color;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			env->nearest_object = calc_object(env->object, &env->intersect,
					&env->ray);
			if (env->nearest_object)
			{
				color = calc_light(env);
			}
			else
				color = env->font_color;
			*(env->img_addr + x + (y * env->size_line) / 4) = color;
		}
	}
}

int					main(int ac, char **av)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		error(INIT, __LINE__ - 1, __FILE__, EXIT);
	if (ac == 2)
	{
		parse_file(av[1], env);
		set_ray(&env->ray, env);
		set_light(&env->light);
		trace(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);
		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
