/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/26 15:01:14 by lgatibel         ###   ########.fr       */
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
	t_p3d	vec;
	if (t <= 0)
		return (-8);
	cpy_tp3d(intersect, mult_nb_tp3d(sum_tp3d(ray->pos, ray->dir), t));
	vec = sub_tp3d(*intersect, ray->pos);
	return (norm(&vec));
//	return (norm(intersect));
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
//	printf("dist[%f]\n", object->dist);
		if (object->dist > 0 && ((!nearest) || (object->dist < nearest->dist)))
			nearest = object;
		object = object->next;
	}
	return (nearest);
}

t_p3d				calc_normal(t_p3d *intersect, t_object *object)
{
	if (object->type == SPHERE)
		return(calc_sphere_normal(intersect, object));
	else if (object->type == CYLINDER)
		return (calc_cylinder_normal(intersect, object));
	else if (object->type == CONE)
		return (calc_cone_normal(object));
	else if (object->type == PLANE)
		return (calc_plane_normal(object));
	set_tp3d(&object->normal, -8, -8, -8);
	return (object->normal);
}

int					calc_light(t_env *env)
{
	t_ray		*light;
	double		angle;
	double		diffuse;
	int			col;
	t_object	*nearest;
	t_p3d		normal;

	nearest = NULL;
	light = &env->light;
	light->dir = sub_tp3d(env->intersect, light->pos);
	nearest = calc_object(env->object, &env->light_intersect, light);
	if (!nearest || env->nearest_object->ptr != nearest->ptr)
	{
		if (!nearest)
		return (YELLOW);//env->font_color);
		return (BLUE);
	}
//	return (nearest->color);
		env->color = nearest->color;
	calc_normal(&env->intersect, nearest);
	normal = nearest->normal;
	normalized(&normal);
	reverse_tp3d(&light->dir);
	normalized(&light->dir);
	angle = mult_tp3d(normal, light->dir);
	if (angle < 0)
	{
//	printf("normal x[%f], y[%f], z[%f]\n",normal.x,normal.y, normal.z);
//	printf("x[%f], y[%f], z[%f]\n",env->intersect.x,env->intersect.y,
//			env->intersect.z);
	}
	//	printf("diffuse[%f], angle[%f]\n", diffuse, angle);
	diffuse = (angle > 0) ? angle * COEFF : 0;
//	printf("light x[%f], y[%f], z[%f]\n", light->dir.x, light->dir.y, light->dir.z);
//	printf("normal x[%f], y[%f], z[%f]\n",normal.x,normal.y, normal.z);
//			env->intersect.z);
//	if (diffuse == 0)
//		return (YELLOW);
//	printf("diffuse[%f], angle[%f]\n", diffuse, angle);
	col = ((int)(color(env->color, RED) * diffuse) << 16) +
	((int)(color(env->color, GREEN) * diffuse) << 8) +
	(int)(color(env->color, BLUE) * diffuse);
	return (col);
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
			if((env->nearest_object = calc_object(env->object, &env->intersect,
					&env->ray)))
				color = calc_light(env);
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
