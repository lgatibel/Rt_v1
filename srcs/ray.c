/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2017/05/08 13:36:46 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <stdio.h>

void				calc_ray(t_env *env, double x, double y)
{
	t_p3d	origin;
	t_p3d	rot;

	set_tp3d(&rot, 0.0f, 0.0f, 1.0f);
	
	rot = rotate_tp3d(&rot, &env->cam.rot);
	// printf("x[%f], y[%f], z[%f]\n", rot.x, rot.y, rot.z);
	// printf("x[%f], y[%f], z[%f]\n", env->cam.rot.x, env->cam.rot.y, env->cam.rot.z);
	origin.x = env->cam.pos.x + (env->cam.focal / 27.5f * rot.y) - env->basis.x / 2.0f;
	origin.y = env->cam.pos.y + (env->cam.focal / 27.5f * rot.x) - env->basis.y / 2.0f;
	origin.z = env->cam.pos.z + (env->cam.focal / 27.5f * rot.z);
	env->ray.dir.x = origin.x + ((double)x * env->indent.x) - env->cam.pos.x;
	env->ray.dir.y = origin.y + ((double)y * env->indent.y) - env->cam.pos.y;
	env->ray.dir.z = origin.z - env->cam.pos.z;
	normalized(&env->ray.dir);
}

void				set_ray(t_ray *ray, t_env *env)
{
	ray->pos.x = env->cam.pos.x;
	ray->pos.y = env->cam.pos.y;
	ray->pos.z = env->cam.pos.z;
	env->cam.focal = env->cam.rot.z / ((double)M_PI / 180.0f);
	env->cam.rot.z = 1.0f;
	printf("x[%f], y[%f], z[%f]\n", env->cam.rot.x, env->cam.rot.y, env->cam.rot.z);
	if (env->cam.focal < 18 || env->cam.focal > 200)
		err(__FILE__, __LINE__,
			"Bad focal must be between 18 and 200; 55 is a good focal", EXIT);
}
