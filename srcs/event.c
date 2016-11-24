/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:56:40 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/24 11:30:40 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static int			close_session(void)
{
	exit(2);
}


static int			manage_event(int keycode)
{
	ft_putnbr(keycode);
	//a retirer
	if (keycode == 53)
		close_session();
	return (1);
}

void				event(t_env *env)
{
	mlx_loop_hook(env->mlx, &test, env);
	mlx_hook(env->win, 2, (1L<<0), &manage_event, &env);
	mlx_hook(env->win, 17, (1L<<17), &close_session, &env);
}
