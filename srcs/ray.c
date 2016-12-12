/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/12 19:30:42 by lgatibel         ###   ########.fr       */
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
//	ray->dir.x = ray->dir.x * cos(cam->rot.z) + ray->dir.y * -sin(cam->rot.z);
//	ray->dir.y = ray->dir.x * sin(cam->rot.z) + ray->dir.y * cos(cam->rot.z);
}

void				set_light(t_light *light)
{
//	set_tp3d(&light->pos, 0.5, 0.5, 100);
	set_tp3d(&light->pos, 300, 300, 100);
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
