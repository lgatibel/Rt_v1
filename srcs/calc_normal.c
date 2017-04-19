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

t_p3d			calc_sphere_normal(t_p3d *intersect, t_object *object)
{
	t_sphere *sphere;

	sphere = (t_sphere *)object->ptr;
	cpy_tp3d(&object->normal, sub_tp3d(*intersect, sphere->pos));
	normalized(&object->normal);
	return (object->normal);
}

t_p3d			calc_cylinder_normal(t_p3d *intersect, t_object *object)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)object->ptr;

	// return (rotate_tp3d(&object->normal, &cylinder->rot));
	// printf("normal\n");
	// printf("x[%f], y[%f], z[%f]\n", object->normal.x, object->normal.y, object->normal.z);
	return (object->normal);

	object->normal = div_nb_tp3d(sub_tp3d(*intersect, cylinder->pos),
		cylinder->radius);
	cpy_tp3d(&object->normal, sub_tp3d(*intersect, cylinder->pos));
	// object->normal = rotate_tp3d(&object->normal, &cylinder->rot);
	// object->normal.y = 0;
	normalized(&object->normal);
	return (rotate_tp3d(&object->normal, &cylinder->rot));
	
	return (object->normal);
}

t_p3d			calc_cone_normal(t_object *object)
{
	set_tp3d(&object->normal, 0, 0, -1);
	normalized(&object->normal);
	return (object->normal);
}

t_p3d			calc_plane_normal(t_object *object)
{
	t_plane *plane;

	plane = (t_plane *)object->ptr;
	normalized(&plane->normal);
	return (plane->normal);
}

t_p3d			calc_normal(t_p3d *intersect, t_object *object)
{
	if (object->type == SPHERE)
		return (calc_sphere_normal(intersect, object));
	else if (object->type == CYLINDER)
		return (calc_cylinder_normal(intersect, object));
	else if (object->type == CONE)
		return (calc_cone_normal(object));
	else if (object->type == PLANE)
		return (calc_plane_normal(object));
	else
		set_tp3d(&object->normal, -8, -8, -8);
	return (object->normal);
}
