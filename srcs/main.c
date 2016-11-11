/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 19:15:47 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>



void				normalized(t_point *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}

static void		trace_test(t_env *env)
{
	double	xindent;
	double	yindent;
	int		x;
	int		y;

	xindent = env->viewplane.width / WIDTH;
	yindent = env->viewplane.height / HEIGHT;
	x = 0;
	y = 0;
}

int					main(void)
{
	t_env		*env;

	env = NULL;
	env = set_env(env);
	set_ray(&env->ray);
	set_sphere(&env->object);
	trace_test(env);
	//trace(env->object, *env);
	mlx_put_image_to_window(env->mlx, env->win,
	env->img, 0, 0);
	write(1, "finish", 6);
	mlx_hook(env->win, 2, (1L<<0), ft_exit, &env);
	mlx_hook(env->win, 17, (1L<<17), ft_exit, &env);
	mlx_loop(env->mlx);
	return (0);
}
