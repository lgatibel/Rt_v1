/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:36:46 by lgatibel          #+#    #+#             */
/*   Updated: 2016/10/07 12:41:15 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_ulltoa_base(unsigned long long nbr, int base)
{
	int			i;
	char		tab[21];
	static char	tab_min[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

	i = -1;
	if (base < 17 && base > 1 && nbr > 0)
	{
		while (nbr)
		{
			tab[++i] = tab_min[nbr % base];
			nbr /= base;
		}
	}
	else if (nbr == 0)
		tab[++i] = '0';
	tab[++i] = '\0';
	return (ft_strdup(ft_reverse_tab(tab, 0, --i)));
}
