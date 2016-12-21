/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:56:34 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/21 12:44:55 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				color(int object_color, int rgb)
{
	if (rgb == RED)
		return ((double)((object_color & RED) >> 16));
	else if (rgb == GREEN)
		return ((double)((object_color & GREEN) >> 8));
	else if (rgb == BLUE)
		return ((double)(object_color & BLUE));
	return (0);
}
