/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:38:57 by lgatibel          #+#    #+#             */
/*   Updated: 2017/04/13 12:38:59 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				calc_norm(t_p3d *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

double				length_ray(t_ray *ray, double t, t_object *object)
{
	t_p3d	intersect;
	t_p3d	tmp;
	t_p3d	res;

 

	if (t <= 0)
		return (-8);
	intersect = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, t));
	res = sub_tp3d(intersect, ray->pos);
	if (object->set == false)
		cpy_tp3d(&object->inter, intersect);
	else
	{
		object->normlight = calc_norm(&res);
		tmp = sub_tp3d(object->inter, ray->pos);
		object->norminter = calc_norm(&tmp);
	}

		double		m;
		t_cylinder	*cyl;

		cyl = (t_cylinder *)object->ptr;
	m = dot_product_tp3d(ray->dir, object->rot) * object->t +
	 dot_product_tp3d(object->offset, object->rot);
	 object->normal = sub_tp3d(sub_tp3d(intersect, cyl->pos), mult_nb_tp3d(object->rot, m));
	object->set = true;

	return (calc_norm(&res));
}
