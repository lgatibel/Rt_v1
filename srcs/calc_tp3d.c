/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tp3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:22:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/26 16:06:37 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

t_p3d			square_tp3d(t_p3d *src)
{
	t_p3d	result;

//	if (!src)
//		return (NULL);
	result.x = src->x * src->x;
	result.y = src->y * src->y;
	result.z = src->z * src->z;
	return (result);
}

void			cpy_tp3d(t_p3d *dest, t_p3d src)
{
//	if (dest && src)
//		return ;
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_p3d			mult_nb_tp3d(t_p3d vector, double nb)
{
	t_p3d		result;

//	if (!vector)
//		return (NULL);
	result.x = vector.x * nb;
	result.y = vector.y * nb;
	result.z = vector.z * nb;
	return (result);
}

t_p3d			sum_tp3d(t_p3d vector1, t_p3d vector2)
{
	t_p3d		result;

//	if (!vector1 || !vector2)
//		return (NULL);
	result.x = vector1.x + vector2.x;
	result.y = vector1.y + vector2.y;
	result.z = vector1.z + vector2.z;
	return (result);
}

t_p3d			sub_tp3d(t_p3d vector1, t_p3d vector2)
{
	t_p3d		result;

//	if (!vector1 || !vector2)
//		return (NULL);
	result.x = vector1.x - vector2.x;
	result.y = vector1.y - vector2.y;
	result.z = vector1.z - vector2.z;
	return (result);
}

//pensez a proteger les fonctions;
