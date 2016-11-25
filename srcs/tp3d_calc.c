/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp3d_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:22:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:38 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_p3d			tp3d_square(t_p3d *src)
{
	t_p3d	result;

	result.x = src->x * src->x;
	result.y = src->y * src->y;
	result.z = src->z * src->z;
	return (result);
}

void			tp3d_cpy(t_p3d *dest,
t_p3d src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_p3d			tp3d_mult_nb(t_p3d tp3d,
double nb)
{
	t_p3d		result;

	result.x = tp3d.x * nb;
	result.y = tp3d.y * nb;
	result.z = tp3d.z * nb;
	return (result);
}

t_p3d			tp3d_sum(t_p3d tp3d1, t_p3d tp3d2)
{
	t_p3d		result;

	result.x = tp3d1.x + tp3d2.x;
	result.y = tp3d1.y + tp3d2.y;
	result.z = tp3d1.z + tp3d2.z;
	return (result);
}

t_p3d			tp3d_sub(t_p3d tp3d1, t_p3d tp3d2)
{
	t_p3d		result;

	result.x = tp3d1.x - tp3d2.x;
	result.y = tp3d1.y - tp3d2.y;
	result.z = tp3d1.z - tp3d2.z;
	return (result);
}
