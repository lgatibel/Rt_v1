/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:25:36 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/01 17:44:13 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <fcntl.h>

int	 main(int ac, const char *av[])
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;
	char	**start;

	i = -1;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((get_next_line(fd, &line) > 0))
		{
			i = -1;
			tab = ft_strsplit(line, ' ');
			start = tab;
			tab++;
			ft_strdel(start);
			while (tab[++i])
				printf("tab[%d] = [%s]\n", i, tab[i]);
			printf("start = [%s] %p\n",start[0], start);
		}
		close(fd);
		
	}
	else
	{
		printf("nope\n");
	}
	return 0;
}
