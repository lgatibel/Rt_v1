/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:38:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 12:25:01 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_ray(t_env *env, double x, double y)
{
			matrice_cpy(&env->ray.dir,
			matrice_sum_1x1(env->viewplane.upleft,
			matrice_sub_1x1(
			matrice_mult_1x1_nb(env->viewplane.rvec,x * env->xindent),
			matrice_mult_1x1_nb(env->viewplane.upvec, y * env->yindent))));
			//facultatif ou necessaire
			if (env->ray.dir.z < 0)
				env->ray.dir.z = -env->ray.dir.z;
		//	normalized(&env->ray.dir);
}

void				set_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->pos.z = -1000;

	ray->dir.x = 0;
	ray->dir.y = 0;
	// a quoi cela sert
	ray->dir.z = 1;
}
