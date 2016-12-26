/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tp3d_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:45:15 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/26 16:06:17 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

double			div_tp3d(t_p3d vector1, t_p3d vector2)
{
	if (!vector1 || !vector2)
		return (ERROR);
	return (vector1.x / vector2.x + vector1.y /
			vector2.y + vector1.z / vector2.z);
}

t_p3d			div_nb_tp3d(t_p3d vector, double nb)
{
	t_p3d	result;

//	if (!vector1)
//		return (NULL);
	result.x = vector.x / nb;
	result.y = vector.y / nb;
	result.z = vector.z / nb;
	return (result);
}

double			mult_tp3d(t_p3d vector1, t_p3d vector2)
{
	if (!vector1 || !vector2)
		return (ERROR);
	return (vector1.x * vector2.x + vector1.y * vector2.y +
		vector1.z * vector2.z);
	
}

double			cross_product_tp3d(t_p3d vector1, t_p3d vector2)
{
	if (!vector1 || !vector2)
		return (ERROR);

	return (ERROR);
	// a definir
	return (vector1.x * vector2.x + vector1.y * vector2.y +
		vector1.z * vector2.z);
}
//fonction a proteger
