/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:12:27 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/01 14:19:43 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				refresh(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void				normalized(t_p3d *point, int length)
{
	point->x = point->x / length;
	point->y = point->y / length;
	point->z = point->z / length;
}
