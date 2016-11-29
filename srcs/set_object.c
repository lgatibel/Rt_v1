/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 17:36:23 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <error.h>

t_object			*set_plane(void)
{
	t_plane		*plane;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	plane->pos.x = 0;
	plane->pos.y = -1;
	plane->pos.z = 0;
	plane->norm.x = 0;
	plane->norm.y = 1;
	plane->norm.z = 0;
	plane->d = 1;
	object->type = PLANE;
	object->color = YELLOW;
	object->ptr = plane;
	object->next = NULL;
	return (object);
}

t_object			*set_cone(void)
{
	t_cone		*cone;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if (!(cone = (t_cone *)malloc(sizeof(t_cone))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	cone->pos.x = 0;
	cone->pos.y = 0;
	cone->pos.z = 250;
//	cone->radius = 1;
	object->type = CONE;
	object->color = RED;
	object->ptr = cone;
	object->next = NULL;
	return (object);
}

t_object			*set_cylinder(void)
{
	t_cylinder	*cylinder;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	cylinder->pos.x = 0;
	cylinder->pos.y = 0;
	cylinder->pos.z = 200;
	cylinder->radius = 20;
	object->type = CYLINDER;
	object->color = WHITE;
	object->ptr = cylinder;
	object->next = NULL;
	return (object);
}

t_object			*set_sphere(void)
{
	t_sphere	*sphere;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 200;
	sphere->radius = 30;
	object->type = SPHERE;
	object->color = GREEN;
	object->ptr = sphere;
	object->next = NULL;
	return (object);
}

void				set_object(t_object **object)
{
	t_object		*obj;
	t_object		*tmp;
	t_object		**start;

	obj = NULL;
	start = NULL;
	obj = set_sphere();
	start = &obj;
	tmp = obj;
	tmp->next = set_cylinder();
	tmp = tmp->next;
	tmp->next = set_cone();
	tmp = tmp->next;
	tmp->next = set_plane();
	*object = *start;
}
