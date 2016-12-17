/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:56:34 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 16:39:41 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				color(int object_color, int rgb)
{
	if (rgb == RED)
		return ((double)((object_color & RED) >> 16) / 255);
	else if (rgb == GREEN)
		return ((double)((object_color & GREEN) >> 8) / 255);
	else if (rgb == BLUE)
		return ((double)((object_color & BLUE)) / 255);
	return (0);
}
