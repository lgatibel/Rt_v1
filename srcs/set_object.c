/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/21 13:40:33 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <error.h>

t_object			*set_cone(void)
{
	t_cone		*cone;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(cone = (t_cone *)malloc(sizeof(t_cone))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	cone->x = 0;
	cone->y = 0;
	cone->z = 0;
	cone->radius = 10;
	cone->height = 1;////////////////////////////////////
	object->type = CONE;
	object->color = RED;
	object->ptr = cone;
	object->next = NULL;
	return (object);
}

t_object			*set_cylinder(void)
{
	t_cylinder *cylinder;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	cylinder->x = 0;
	cylinder->y = 0;
	cylinder->z = 0;
	cylinder->radius = 50;
	cylinder->height = 5;/////////////////////////////////
	object->type = CYLINDER;
	object->color = RED;
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
	if(!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	sphere->x = 0;
	sphere->y = 0;
	sphere->z = 0;
	sphere->radius = 150;
	object->type = SPHERE;
	object->color = GREEN;
	object->ptr = sphere;
	object->next = NULL;
	return (object);
}

void			set_object(t_object **object)
{
	t_object		*obj;
	t_object		*tmp;
	t_object		**start;

	obj = NULL;
	start = NULL;
	if (obj == NULL)
	{
		obj = set_sphere();
	//	obj = set_cylinder();
		start = &obj;
	}
	obj->next = set_cylinder();
	tmp = obj->next;
	tmp->next = set_cone();
	*object = *start;
}
