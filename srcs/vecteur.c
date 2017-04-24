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
	// double		m;
	// t_cylinder	*cyl;
	t_p3d		intersect;
	t_p3d		res;
	// t_p3d		rot;

	if (t <= 0)
		return (-8);
	intersect = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, t));
	res = sub_tp3d(intersect, ray->pos);
	// cyl = (t_cylinder *)object->ptr;
	// if (!object->set)
	// {
		// cpy_tp3d(&object->inter, intersect);
		// object->offset = sub_tp3d(ray->pos, cyl->pos);
		// set_tp3d(&rot, 0, 1, 0);

		// rot = rotate_tp3d(&object->rot, &cyl->rot);
		// m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	 	// dot_product_tp3d(object->offset, rot);

		// object->normal = sub_tp3d(sub_tp3d(intersect, cyl->pos),
		// mult_nb_tp3d(rot, m));
		// normalized(&object->normal);
	// }
	object->set = true;
	return (calc_norm(&res));
}