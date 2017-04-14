/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:10:19 by lgatibel          #+#    #+#             */
/*   Updated: 2017/04/13 14:10:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int					calc_light(t_env *env)
{
	t_ray		*light;
	double		angle;
	double		diffuse;
	int			col;
	t_object	*nearest;

	nearest = NULL;
	light = &env->light;
	light->dir = sub_tp3d(env->nearest_object->inter, light->pos);
	normalized(&light->dir);
	if (!(nearest = calc_object(env->object, light)) ||
	env->nearest_object != nearest)
		return (FONT);

	// 	diffuse = 1.0f;
	// return (col = ((int)(color(nearest->color, RED) * diffuse) << 16) +
	// ((int)(color(nearest->color, GREEN) * diffuse) << 8) +
	// (int)(color(nearest->color, BLUE) * diffuse));


	reverse_tp3d(&light->dir);
	
	nearest->normal = calc_normal(&nearest->inter, nearest);
	normalized(&nearest->normal);

	// light->dir = rotate_tp3d(&light->dir, &env->nearest_object->rot);
	normalized(&light->dir);
	angle = dot_product_tp3d(nearest->normal, light->dir);
	diffuse = (angle > 0) ? angle * COEFF : 0;
	// diffuse = (angle > 0) ? angle * COEFF : -angle * COEFF;
	col = ((int)(color(nearest->color, RED) * diffuse) << 16) +
	((int)(color(nearest->color, GREEN) * diffuse) << 8) +
	(int)(color(nearest->color, BLUE) * diffuse);
	return ((col < 0) ? 0x00 : col);
}
