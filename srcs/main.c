/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2017/05/02 10:07:22 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_object			*calc_object(t_object *object, t_ray *ray)
{
	double		t;
	t_object	*nearest;

	t = -1;
	nearest = NULL;
	while (object)
	{
		if (object->type == SPHERE)
			t = calc_sphere(object, ray);
		else if (object->type == CYLINDER)
			t = calc_cylinder(object, ray);
		else if (object->type == CONE)
			t = calc_cone(object, ray);
		else if (object->type == PLANE)
			t = calc_plane(object, ray);
		object->dist = length_ray(ray, t, object);
		if (object->dist > 0.0f && ((!nearest) ||
		(object->dist < nearest->dist + PREC)))
			nearest = object;
		object = object->next;
	}
	return (nearest);
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
			reset_object(env->object);
			calc_ray(env, x, y);
			if ((env->nearest_object = calc_object(env->object, &env->ray)))
				color = calc_light(env);
			else
				color = FONT;
			*(env->img_addr + x + (y * env->size_line) / 4) = color;
		}
	}
}

void				set_offset(t_object *object, t_ray *ray)
{
	t_sphere *o;

	o = object->ptr;
	object->offset = sub_tp3d(ray->pos, o->pos);
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
		trace(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);
		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
