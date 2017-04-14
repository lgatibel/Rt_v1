/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 15:37:32 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/21 15:46:42 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_is_space(const char c)
{
	static char	tab[6] = {'\n', '\t', '\v', '\r', '\f', ' '};
	int			index;

	index = -1;
	while (tab[++index] && tab[index] != c)
		;
	if (index > 5 && !ft_isdigit(c))
		return (0);
	return (1);
}
