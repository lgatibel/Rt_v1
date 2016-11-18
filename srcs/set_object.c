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

void				set_cylinder(t_object **object)
{
	t_cylinder *cylinder;

	if (!((*object)->next = (t_object *)malloc(sizeof(t_object))))
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

	if (!(*object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	if(!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__, EXIT);
	sphere->x = 0;
	sphere->y = 0;
	sphere->z = 0;
	sphere->radius = 150;
	(*object)->type = SPHERE;
	(*object)->color = GREEN;
	(*object)->ptr = sphere;
	(*object)->next = NULL;
}
/*
void				set_object(t_object object)
{
	
}
*/
