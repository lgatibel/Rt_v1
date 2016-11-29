/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 16:35:46 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_ray(t_env *env, double x, double y)
{
	cpy_tp3d(&env->ray.dir,
	sum_tp3d(env->viewplane.upleft,
	sub_tp3d(
	mult_nb_tp3d(env->viewplane.rvec, x * env->xindent),
	mult_nb_tp3d(env->viewplane.upvec, y * env->yindent))));
	normalized(&env->ray.dir, env->ray.length);
//	printf("X = %f, Y = %f\n", x,y);
}

void				set_ray(t_ray *ray, t_cam *cam)
{
	ray->pos.x = cam->pos.x;
	ray->pos.y = cam->pos.y;
	ray->pos.z = cam->pos.z;
	ray->dir.x = cam->rot.x;
	ray->dir.y = cam->rot.y;
	ray->dir.z = cam->rot.z;
	ray->length = 1;
}
