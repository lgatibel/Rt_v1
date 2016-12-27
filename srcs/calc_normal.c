/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:26:15 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/27 12:17:53 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_p3d			calc_sphere_normal(t_p3d *intersect, t_object *object)
{
	t_sphere *sphere;

	sphere = (t_sphere *)object->ptr;
	return (div_nb_tp3d(sub_tp3d(*intersect, sphere->pos), sphere->radius));
}

t_p3d			calc_cylinder_normal(t_p3d *intersect, t_object *object)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)object->ptr;
	object->normal = div_nb_tp3d(sub_tp3d(*intersect, cylinder->pos),
			cylinder->radius);
	object->normal.y = 0;
	return (object->normal);
}

t_p3d			calc_cone_normal(t_object *object)
{
	set_tp3d(&object->normal, 0, 0, 1);
	return (object->normal);
}

t_p3d			calc_plane_normal(t_object *object)
{
	t_plane *plane;

	plane = (t_plane *)object->ptr;
	return (plane->normal);
}
