/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2017/02/09 17:20:27 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_ray(t_env *env, double x, double y)
{
	t_p3d	origin;

	env->cam.focal = 55;
	origin.x = env->cam.pos.x + (env->cam.focal / 27.5f * 0.0f) - env->basis.x / 2.0f;
	origin.y = env->cam.pos.y + (env->cam.focal / 27.5f * 0.0f) - env->basis.y / 2.0f;
	origin.z = env->cam.pos.z + (env->cam.focal / 27.5f * 1.0f);
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
}
