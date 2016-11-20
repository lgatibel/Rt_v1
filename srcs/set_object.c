/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 16:18:54 by lgatibel         ###   ########.fr       */
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


void				set_cylinder(t_object **object)
{
	t_cylinder *cylinder;

	//malloc_object(object);
		if (!(*object = (t_object *)malloc(sizeof(t_object))))
			error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	cylinder->x = 0;
	cylinder->y = 0;
	cylinder->z = 0;
	cylinder->radius = 50;
	cylinder->height = 100;
	(*object)->type = CYLINDER;
	(*object)->color = RED;
	(*object)->ptr = cylinder;
	(*object)->next = NULL;
}

void				set_sphere(t_object **object)
{
	t_sphere *sphere;

	//malloc_object(object);
		if (!(*object = (t_object *)malloc(sizeof(t_object))))
			error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	sphere->x = 0;
	sphere->y = 0;
	sphere->z = 10;
	sphere->radius = 50;
	(*object)->type = SPHERE;
	(*object)->color = GREEN;
	(*object)->ptr = sphere;
	(*object)->next = NULL;
}

void			set_object(t_object **object)
{
		set_cylinder(&(*object));
	//	set_sphere(&(*object));
	//	set_cylinder(&(*object)->next);
}
/*
void				set_object(t_object object)
{
	
}
*/
