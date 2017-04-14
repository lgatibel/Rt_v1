/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:11:15 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/17 14:40:18 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char const *c, int fd)
{
	int i;

	i = 0;
	if (c)
	{
		while (c[i])
		{
			ft_putchar_fd((char)c[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
