/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:26:15 by lgatibel          #+#    #+#             */
/*   Updated: 2017/01/25 12:22:11 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				calc_plane_normal(t_ray *ray, t_object *object, t_p3d rot,
double div)
{
	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	if (div < 0.0f)
		cpy_tp3d(&object->normal, rot);
	else
		cpy_tp3d(&object->normal, mult_nb_tp3d(rot, -1));
	normalized(&object->normal);
}

void				calc_cone_normal(t_ray *ray, t_object *object, t_p3d rot,
double tanj)
{
	t_cone		*cone;
	double		m;

	cone = (t_cone *)object->ptr;
	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	dot_product_tp3d(object->offset, rot);
	object->normal = sub_tp3d(sub_tp3d(object->inter, cone->pos),
	mult_nb_tp3d(mult_nb_tp3d(rot, m), tanj));
	normalized(&object->normal);
}

void				calc_cylinder_normal(t_ray *ray, t_object *object,
t_p3d rot)
{
	t_cylinder	*cyl;
	double		m;

	cyl = (t_cylinder *)object->ptr;
	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	dot_product_tp3d(object->offset, rot);
	object->normal = sub_tp3d(sub_tp3d(object->inter, cyl->pos),
	mult_nb_tp3d(rot, m));
	normalized(&object->normal);
}

void				calc_sphere_normal(t_ray *ray, t_object *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object->ptr;
	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	object->normal = sub_tp3d(object->inter, sphere->pos);
	normalized(&object->normal);
}
