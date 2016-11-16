/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/16 15:56:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				calc_delta(t_env *env, double *t0, double *t1)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;
	t_ray		*ray;

	s = (t_sphere *)env->object->ptr;
	ray = (t_ray *)&env->ray;
	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
		ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->x) + ray->dir.y * (ray->pos.y - s->y)		+ ray->dir.z * (ray->pos.z - s->z));
	c = ((ray->pos.x - s->x) * (ray->pos.x - s->x) + (ray->pos.y - s->y) *
		(ray->pos.y - s->y) + (ray->pos.z - s->z) * (ray->pos.z - s->z)) -
		s->radius * s->radius;
	*t0 = (-b + sqrt((b * b) - c));//(4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - c));//(4 * a * c))) / (2 * a);
	return ((b * b) - (4 * a * c));
}

void				normalized(t_point *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}

