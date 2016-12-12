/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:12:27 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/12 19:33:54 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				malloc_object(t_object **obj, t_object **object, int i)
{
	if (i <= 0)
	{
		if (!(*obj = (t_object *)malloc(sizeof(t_object))))
			err(__FILE__, __LINE__, "malloc error !!", EXIT);
		*object = *obj;
		(*obj)->next = NULL;
	}
	else
	{
		if (!((*obj)->next = (t_object *)malloc(sizeof(t_object))))
			err(__FILE__, __LINE__, "malloc error !!", EXIT);
		*obj = (*obj)->next;
		(*obj)->next = NULL;
	}
}

void				print_line(char **str)
{
	ft_putendl(*str);
	ft_strdel(str);
}

void				refresh(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void				normalized(t_p3d *point, int length)
{
	double		norm;

	norm = sqrt(point->x * point->x + point->y * point->y +
			point->z * point->z);
	// length a supprimer
	length = norm;
	point->x = point->x / norm;
	point->y = point->y / norm;
	point->z = point->z / norm;
}
