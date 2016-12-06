/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 17:54:00 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				calc_object(t_object *object, t_env **env)
{
	double		dist;
	double		t;

	t = -1;
	while (object)
	{
		if (object->type == SPHERE)
			dist = calc_sphere(object, &(*env)->ray);
		else if (object->type == CYLINDER)
			dist = calc_cylinder(object, &(*env)->ray);
		else if (object->type == CONE)
			dist  = calc_cone(object, &(*env)->ray);
		else if (object->type == PLANE)
			dist = calc_plane(object, &(*env)->ray);
		if (dist > 0 && ((dist < t) || t == -1))
		{
			(*env)->color = object->color;
			t = dist;
		}
		object = object->next;
	}
	return (t);
}

void				trace_test(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			if (calc_object(env->object, &env) >= 0)
			{
				*(env->img_addr + x + (y * env->size_line) / 4) =
					color(env->color, 1);
			}
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
		set_ray(&env->ray, &env->cam);
		trace_test(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);
		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
