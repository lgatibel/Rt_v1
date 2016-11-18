/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 16:17:26 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

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
			delta = calc_delta(env, &t0, &t1);
			if (delta >= 0)
			{
				*(env->img_addr + (int)x + ((int)y * env->size_line) / 4) =
					color(GREEN, 1);
		printf("delta = %f\n", delta);
			}
		}
	}
}

int					main(int ac, char **av)
{
	t_grtv1		global;
	t_env		*env;
	t_object	*object;

	env = global.env;
	object = global.object;
	if (ac == 2)
	{
		parse_file(av[1], &env, &object);

		set_ray(&env->ray);
		set_sphere(&env->object);
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
