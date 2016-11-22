/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/22 15:52:00 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <error.h>
t_object			*set_plan(void)
{
	t_plan		*plan;
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(plan = (t_plan *)malloc(sizeof(t_plan))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	plan->x = 0;
	plan->y = 0;
	plan->z = 0;
	plan->t = 0;
	plan->u = 0;
	plan->v = 0;
	object->type = PLAN;
	object->color = YELLOW;
	object->ptr = plan;
	object->next = NULL;
	return (object);
}

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
	cone->radius = 1;
	cone->height = 10;
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
	cylinder->radius = 40;
	cylinder->height = 5;/////////////////////////////////
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
	if(!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	sphere->x = 0;
	sphere->y = 0;
	sphere->z = 10;
	sphere->radius = 100;
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
//	if (obj == NULL)
//	{
		obj = set_sphere();
	//	obj = set_cylinder();
		start = &obj;
//	}
	tmp = obj;
	tmp->next = set_cylinder();
	tmp = obj->next;
	tmp->next = set_cone();
	tmp = obj->next;
//	tmp->next = set_plan();
	*object = *start;
}
