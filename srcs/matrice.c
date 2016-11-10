/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:22:33 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/09 17:23:24 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

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

void				set_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->pos.z = -1000;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 1;
	//ray direction normalized
}
