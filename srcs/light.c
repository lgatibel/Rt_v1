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
static t_ray		*set_light(t_env *env)
{
	env->light.dir = sub_tp3d(env->nearest_object->inter, env->light.pos);
	normalized(&env->light.dir);
	return (&env->light);
}

int					calc_light(t_env *env)
{
	t_ray		*light;
	double		angle;
	double		diffuse;
	int			col;
	t_object	*nearest;


	light = set_light(env);
	if (!(nearest = calc_object(env->object, light)) ||
	env->nearest_object != nearest)
	{
		return (FONT);
	}
	reverse_tp3d(&light->dir);

	angle = dot_product_tp3d(nearest->normal, light->dir);
	diffuse = (angle > 0.0f) ? angle * COEFF : 0;

	col = ((int)(color(nearest->color, RED) * diffuse) << 16) +
	((int)(color(nearest->color, GREEN) * diffuse) << 8) +
	(int)(color(nearest->color, BLUE) * diffuse);
	return ((col < 0) ? 0x00 : col);
}
