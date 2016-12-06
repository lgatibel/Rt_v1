/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:12:27 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 16:45:47 by lgatibel         ###   ########.fr       */
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
	point->x = point->x / length;
	point->y = point->y / length;
	point->z = point->z / length;
}
