/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/09 16:54:19 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				set_sphere(t_object **object)
{
	t_sphere *sphere;

	*object = (t_object *)malloc(sizeof(t_object));
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->pos.x = 240;
	sphere->pos.y = 240;
	sphere->pos.z = 0;
	sphere->radius = 240;
	(*object)->type = SPHERE;
	(*object)->ptr = sphere;
}
