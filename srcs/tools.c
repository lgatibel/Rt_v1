/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:12:27 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 18:20:10 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				refresh(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void				normalized(t_p3d *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}
