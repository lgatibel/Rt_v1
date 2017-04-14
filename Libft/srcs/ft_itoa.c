/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:49:02 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/09 14:44:32 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_compte(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i;

	i = 0;
	nb = (char *)malloc(sizeof(char) * ((unsigned)ft_compte(n) + 1));
	if (!nb)
		return (NULL);
	if (n == -2147483648)
		return (ft_strsub("-2147483648", 0, 11));
	i = ft_compte(n);
	nb[ft_compte(n)] = '\0';
	while (i > 0 && n != -2147483648)
	{
		i--;
		if (n < 0)
			n = -n;
		nb[i] = n % 10 + 48;
		n = n / 10;
	}
	if (nb[0] == '0' && nb[1] != '\0')
		nb[0] = '-';
	return (nb);
}
