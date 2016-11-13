/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:22:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 12:39:02 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
void			matrice_cpy(t_point *dest,
t_point src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_point			matrice_mult_1x1_nb(t_point matrice,
double nb)
{
	t_point		result;

	result.x = matrice.x * nb;
	result.y = matrice.y * nb;
	result.z = matrice.z * nb;
	return (result);
}

t_point			matrice_sum_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x + matrice2.x;
	result.y = matrice1.y + matrice2.y;
	result.z = matrice1.z + matrice2.z;
	return (result);
}

t_point			matrice_sub_1x1(t_point matrice1, t_point matrice2)
{
	t_point		result;
	result.x = matrice1.x - matrice2.x;
	result.y = matrice1.y - matrice2.y;
	result.z = matrice1.z - matrice2.z;
	return (result);
}

double			matrice_mult_1x1(t_point matrice1, t_point matrice2)
{
	double		result;
	result = matrice1.x * matrice2.x;
	result += matrice1.y * matrice2.y;
	result += matrice1.z * matrice2.z;
	return (result);
}
