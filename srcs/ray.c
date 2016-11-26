/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 18:33:16 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_ray(t_env *env, double x, double y)
{
	tp3d_cpy(&env->ray.dir,
	tp3d_sum(env->viewplane.upleft,
	tp3d_sub(
	tp3d_mult_nb(env->viewplane.rvec, x * env->xindent),
	tp3d_mult_nb(env->viewplane.upvec, y * env->yindent))));
	normalized(&env->ray.dir);
}

void				set_ray(t_ray *ray, t_cam *cam)
{
	ray->pos.x = cam->pos.x;
	ray->pos.y = cam->pos.y;
	ray->pos.z = cam->pos.z;
	ray->dir.x = cam->rot.x;
	ray->dir.y = cam->rot.y;
	ray->dir.z = 1.0f;//cam->rot.z;
}
