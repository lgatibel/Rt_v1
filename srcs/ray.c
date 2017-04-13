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

	ray = &env->ray;
	cam = &env->cam;
	cpy_tp3d(&env->ray.dir,
	sum_tp3d(env->viewplane.upleft,
	sub_tp3d(
	mult_nb_tp3d(env->viewplane.rvec, x * env->xindent),
	mult_nb_tp3d(env->viewplane.upvec, y * env->yindent))));
	normalized(&env->ray.dir);

	// t_p3d	basis;
	// t_p3d	origin;
	// t_p3d	indent;
	// t_cam	*cam;

	// cam = &env->cam;
	// cam->focal = 55;
	// basis.y = 1.0f;
	// basis.x = WIDTH / HEIGHT;
	// indent.y = basis.y / HEIGHT;
	// indent.x = basis.x / WIDTH;

	// origin.x = cam->pos.x + (cam->focal / 27.5f * cam->rot.x) - basis.x / 2.0f;
	// origin.y = cam->pos.y + (cam->focal / 27.5f * cam->rot.y) - basis.y / 2.0f;
	// origin.z = cam->pos.z + (cam->focal / 27.5f * cam->rot.z);
	// env->ray.dir.x = origin.x + ((double)x * indent.x) - cam->pos.x;
	// env->ray.dir.y = origin.y + ((double)y * indent.y) - cam->pos.y;
	// env->ray.dir.z = origin.z - cam->pos.z;
	// normalized(&env->ray.dir);
}

void				set_light(t_ray *light)
{
	set_tp3d(&light->pos, 0, 0, 400);
	set_tp3d(&light->dir, 0, 0, 0);
	light->next = NULL;
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
