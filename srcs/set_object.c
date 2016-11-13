/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:37:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 19:11:43 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <error.h>

void				set_sphere(t_object **object)
{
	t_sphere *sphere;

	if (!(*object = (t_object *)malloc(sizeof(t_object))))
		error(MALLOC, __LINE__ - 1, __FILE__);
	if(!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error(MALLOC, __LINE__ - 1, __FILE__);
	sphere->x = WIDTH / 2;
	sphere->y = HEIGHT / 2;
	sphere->z = 0;
	sphere->radius = 100;
	(*object)->type = SPHERE;
	(*object)->ptr = sphere;
}
