/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:45:15 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 11:57:17 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

double			div_tp3d(t_p3d vector1, t_p3d vector2)
{
	double		result;

	result = vector1.x / vector2.x;
	result += vector1.y / vector2.y;
	result += vector1.z / vector2.z;
	return (result);
}

double			mult_tp3d(t_p3d vector1, t_p3d vector2)
{
	double		result;

	result = vector1.x * vector2.x;
	result += vector1.y * vector2.y;
	result += vector1.z * vector2.z;
	return (result);
}