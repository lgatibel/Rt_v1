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
	t_p3d	res;

	if (t <= 0)
		return (-8);
	intersect = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, t));
	res = sub_tp3d(intersect, ray->pos);

	if (!object->set)
		cpy_tp3d(&object->inter, intersect);
	
	double		m;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)object->ptr;

	if (!object->set)
	{
	// m = dot_product_tp3d(ray->dir, rot) * object->t +
	// dot_product_tp3d(object->offset, rot);
	// object->offset = sub_tp3d(ray->pos, cyl->pos);
		// object->offset = rotate_tp3d2(ray->pos, cyl->pos, &cyl->rot);
		t_p3d	rot;
		t_p3d	test;
		set_tp3d(&test, 0, 00, 0);

		// object->offset = rotate_tp3d2(test,	cyl->pos, &cyl->rot);
		rot = rotate_tp3d(&object->rot, &cyl->rot);


		 m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	 	dot_product_tp3d(object->offset, rot);

		object->normal = sub_tp3d(sub_tp3d(intersect, cyl->pos), mult_nb_tp3d(rot, m));
		// printf("vecteur\n");
		// printf("x[%f], y[%f], z[%f]\n", object->normal.x, object->normal.y, object->normal.z);
		
		normalized(&object->normal);
		// printf("x[%f], y[%f], z[%f]\n", object->normal.x, object->normal.y, object->normal.z);
	}
	object->set = true;
	return (calc_norm(&res));
}
