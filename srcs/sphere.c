/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:36:45 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 14:39:32 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_bool				calc_sphere(t_object *object,t_ray ray, double *t)
{
	double		b;
	double		delta;
	double		t0;
	double		t1;
	t_sphere	*sphere;
	t_p3d		dist;

	sphere = (t_sphere *)object->ptr;
//	dist = tp3d_sub(sphere->pos, ray.pos);
	b = tp3d_mult(ray.dir, dist);
	delta = ((b * b) - tp3d_mult(dist, dist) + (sphere->radius * sphere->radius));
	t0 = b - sqrt(delta);
	t1 = b + sqrt(delta);
	if (t0 > 0.1f && t0 < *t)
		*t = t0;
	else if (t1 > 0.1f && t1 < *t)
		*t = t1;
	else
		return (false);
//	printf("t0 = %f, t1 = %f, delta = %f, b = %f, t = %f\n", t0, t1, delta, b, *t);
	return (true);
}
