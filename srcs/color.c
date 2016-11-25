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

int				color(int color, double t)
{
	int		red;
	int		green;
	int		blue;
	int		result;

	result = 0;
	t = result;
	red = (color & 0xFF0000);
	green = (color & 0x00FF00);
	blue = (color & 0x0000FF);
	result = red + green + blue;
	t = red;
	return (result);
}
