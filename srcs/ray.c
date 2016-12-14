/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/14 19:49:32 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_ray(t_env *env, double x, double y)
{
	t_ray *ray;
	t_cam *cam;

	ray = &env->ray;
	cam = &env->cam;
	cpy_tp3d(&env->ray.dir,
	sum_tp3d(env->viewplane.upleft,
	sub_tp3d(
	mult_nb_tp3d(env->viewplane.rvec, x * env->xindent),
	mult_nb_tp3d(env->viewplane.upvec, y * env->yindent))));
	normalized(&env->ray.dir, env->ray.length);
}

void				set_light(t_light *light)
{
	set_tp3d(&light->pos, 0, 0, 421);
	set_tp3d(&light->dir, 0, 0, 0);
}

void				set_ray(t_ray *ray, t_env *env)
{
	ray->pos.x = env->cam.pos.x;
	ray->pos.y = env->cam.pos.y;
	ray->pos.z = env->cam.pos.z;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 1;
// a quoi sert ceci ???
	ray->length = 1;
	// cette variable doit etre fixe ou pas ???
}
