/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:25:36 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/13 17:00:51 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <fcntl.h>

int	 main(int ac, const char **av)
{
	int		i;
	int		color;
	int		red;
	int		green;
	int		blue;

	i = 0;
	if (ac == 3)
	{
		color = ft_atoi_base(av[1], ft_atoi(av[2]));
		red = (color >> 16) & 0xFF;
		green = (color >> 8) & 0xFF;
		blue = color & 0xFF;
		printf("red[%d], green[%d], blue[%d]",red, green, blue);
	}
	else
		printf("Nope\n");
	return 0;
}
