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
	t_ray *ray;
	t_cam *cam;
	t_p3d	origin;


	ray = &env->ray;
	cam = &env->cam;

	// a metre dans set_env.c

	cam->focal = 55;
	origin.x = cam->pos.x + (cam->focal / 27.5f * 0.0f) - env->basis.x / 2.0f;
	origin.y = cam->pos.y + (cam->focal / 27.5f * 0.0f) - env->basis.y / 2.0f;
	origin.z = cam->pos.z + (cam->focal / 27.5f * 1.0f);
	ray->dir.x = origin.x + ((double)x * env->indent.x) - cam->pos.x;
	ray->dir.y = origin.y + ((double)y * env->indent.y) - cam->pos.y;
	ray->dir.z = origin.z - cam->pos.z;
	normalized(&ray->dir);

	// 	basis.y = 1.0f;
	// basis.x = WIDTH / HEIGHT;
	// indent.y = basis.y / HEIGHT;
	// indent.x = basis.x / WIDTH;

	// origin.x = cam->pos.x + (cam->focal / 27.5f * cam->rot.x) - basis.x / 2.0f;
	// origin.y = cam->pos.y + (cam->focal / 27.5f * cam->rot.y) - basis.y / 2.0f;
	// origin.z = cam->pos.z + (cam->focal / 27.5f * cam->rot.z);
	// direction.x = origin.x + ((float)x * indent.x) - cam->pos.x;
	// direction.y = origin.y + ((float)y * indent.y) - cam->pos.y;
	// direction.z = origin.z - cam->pos.z;
}

void				set_ray(t_ray *ray, t_env *env)
{
	ray->pos.x = env->cam.pos.x;
	ray->pos.y = env->cam.pos.y;
	ray->pos.z = env->cam.pos.z;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 0;
	ray->next = NULL;
}
