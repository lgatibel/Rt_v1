/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:12:27 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/20 16:27:26 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				malloc_object(t_object **obj, t_object **object, int i)
{
	if (!i)
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

void				normalized(t_p3d *point)
{
	double		norm;

	norm = sqrt(point->x * point->x + point->y * point->y +
			point->z * point->z);
	point->x /= norm;
	point->y /= norm;
	point->z /= norm;
}
