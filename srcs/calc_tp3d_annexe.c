/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tp3d_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:45:15 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/26 16:21:21 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

double			div_tp3d(t_p3d vector1, t_p3d vector2)
{
	return (vector1.x / vector2.x + vector1.y /
			vector2.y + vector1.z / vector2.z);
}

t_p3d			div_nb_tp3d(t_p3d vector, double nb)
{
	t_p3d	result;

	result.x = vector.x / nb;
	result.y = vector.y / nb;
	result.z = vector.z / nb;
	return (result);
}

double			dot_product_tp3d(t_p3d vector1, t_p3d vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y +
		vector1.z * vector2.z);
}

double			cross_product_tp3d(t_p3d vector1, t_p3d vector2)
{
	return (vector1.x * vector2.x - vector1.y * vector2.y -
		vector1.z * vector2.z);
}

void			reverse_tp3d(t_p3d *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}
