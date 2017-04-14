/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:21:19 by lgatibel          #+#    #+#             */
/*   Updated: 2016/10/18 10:38:50 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		test_sign(long long *nbr, int base, char *tab, int *i)
{
	if (*nbr < 0 && base == 10)
	{
		tab[++*i] = '-';
		*nbr = -*nbr;
		return (1);
	}
	return (0);
}

char			*ft_lltoa_base(long long nbr, int base)
{
	int			i;
	char		tab[21];
	static char	tab_min[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	int			sign;

	i = -1;
	if (nbr == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	sign = test_sign(&nbr, base, tab, &i);
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
	return (ft_strdup(ft_reverse_tab(tab, sign, --i)));
}
