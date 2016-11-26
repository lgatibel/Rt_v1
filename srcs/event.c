/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:56:40 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 16:55:28 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void			move_camera(int keycode, t_env **env)
{
	printf("lol\n");
	ft_putnbr(keycode);
	ft_putchar('\n');
	keycode = (*env)->t;
/*	if (keycode ==)
	else if (keycode ==)
	else if (keycode ==)
	else if (keycode ==)*/
}

static int			close_session(void)
{
	exit(2);
}

static int			manage_event(int keycode, t_env **env)
{
	if (keycode > 1 && keycode < 1)
		move_camera(keycode, env);
	else if (keycode == 53)
		close_session();
	return (1);
}

void				event(t_env *env)
{
	mlx_hook(env->win, 2, (1L <<  0), &manage_event, &env);
	mlx_hook(env->win, 17, (1L << 17), &close_session, &env);
	mlx_loop_hook(env->mlx, &test, env);
}
