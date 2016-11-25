/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp3d_calc_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:45:15 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:52 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double			tp3d_div(t_p3d tp3d1, t_p3d tp3d2)
{
	double		result;

	result = tp3d1.x / tp3d2.x;
	result += tp3d1.y / tp3d2.y;
	result += tp3d1.z / tp3d2.z;
	return (result);
}

double			tp3d_mult(t_p3d tp3d1, t_p3d tp3d2)
{
	double		result;

	result = tp3d1.x * tp3d2.x;
	result += tp3d1.y * tp3d2.y;
	result += tp3d1.z * tp3d2.z;
	return (result);
}
