/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:56:34 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 12:24:58 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int				color(int color, double t)
{
	int		red;
	int		green;
	int		blue;
	int		result;
	int		color2;

//	printf("0xFF0000 = %d, 0xFF0000 = %d, 0xFF0000 = %d, calc = %d\n",0xFF0000, 0x00FF00, 0x0000FF, 0xFF0000 >> 24 );
	color2 = 0x000800;
	red = (color & 0xFF0000);
	green = (color & 0x00FF00) + t;// * (1.0f - ((RAYON_SIZE - t) / (RAYON_SIZE - 240)));
	blue = (color & 0x0000FF);
//	printf("red %d,green %d,blue %d\n",red, green, blue);
	result = red + green + blue;
	t = red;
	return (result);
}
