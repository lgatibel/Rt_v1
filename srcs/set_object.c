/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/21 10:40:10 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <error.h>

void				malloc_object(t_object **object)
{
	if (*object)
	{
		printf("1\n");
		if (!((*object)->next = (t_object *)malloc(sizeof(t_object))))
			error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
		*object = (*object)->next;
	}
	else
	{
		printf("2\n");
		if (!(*object = (t_object *)malloc(sizeof(t_object))))
			error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	}
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
	cylinder->height = 10;
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
	t_object		**start;

	obj = NULL;
	if (obj == NULL)
	{
		obj = set_sphere();
		start = &obj;
	}
	obj->next = set_cylinder();
	*object = *start;
}
