/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/21 15:22:36 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double			calc_delta(t_object *object, double *t0, double *t1,
t_env **env)
{
	double		delta;
	double		tmp;
	double		t;

	delta = -1;
	tmp = -1;
	t = -1;
	while (object)
	{
		//printf("type = %d\n", object->type);
		if (object->type == SPHERE)
			tmp = calc_sphere(object, t0, t1, &(*env));
		else if (object->type == CYLINDER)
			tmp = calc_cylinder(object, t0, t1, &(*env));
		else if (object->type == CONE)
			tmp = calc_cone(object, t0, t1, &(*env));
	//	if (tmp > -1 && (tmp < delta || delta == -1) &&
		if (tmp > -1 //&& (delta == -1 || tmp < delta)) //&&
		 && ((t >= (*env)->t && (*env)->t > -1) || ((*env)->t > -1 && t == -1)))
		{
			delta = tmp;
			(*env)->color = object->color;
		}
	//	printf("t = %f\n",(*env)->t);
		t = (*env)->t;
		object = object->next;
	}
	//
//	printf("delta = %f, tmp = %f\n",delta, tmp);
	return (delta);
}

static void		trace_test(t_env *env)
{
	int		x;
	int		y;
	double		t0;
	double		t1;
	double		delta;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			delta = calc_delta(env->object, &t0, &t1, &env);
			if (delta >= 0)
			{
				*(env->img_addr + x + (y * env->size_line) / 4) =
				color(env->color, 1);
	//	printf("delta = %f\n", delta);
			}
		}
	}
}

void				set_global(t_grtv1 *global)
{
	global->env = NULL;
	global->object = NULL;
	global->ray = NULL;
}

int					main(int ac, char **av)
{
	t_grtv1		global;
	t_env		*env;
	t_object	*object;

// a voir plus tard si le global est interessant
	set_global(&global);
	object = NULL;
	env = NULL;
	if (ac == 2)
	{
		parse_file(av[1], &env, &object);

		set_ray(&env->ray);
		trace_test(env);
		//trace(env->object, *env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);

		write(1, "finish", 6);

		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
