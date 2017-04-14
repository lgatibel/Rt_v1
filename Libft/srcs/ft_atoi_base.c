/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:27:52 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 09:57:40 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_base(char str, int base)
{
	static char		tab_maj[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	static char		tab_min[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int				i;

	i = -1;
	while (tab_min[++i] && i < base)
		if (str == tab_min[i] || str == tab_maj[i])
			return (i);
	return (-1);
}

static int		ft_calc(const char *str, int i, int base)
{
	int		n;
	int		pow;
	int		tmp;

	n = 0;
	i -= 1;
	pow = -1;
	while (ft_ishexa(str[++i]))
		;
	while (ft_ishexa(str[--i]))
	{
		if ((tmp = ft_base(str[i], base)) == -1)
			break ;
		n += (ft_power(base, ++pow)) * tmp;
	}
	return (n);
}

int				ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;

	i = -1;
	sign = 1;
	if (base > 0 && base < 17)
	{
		if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "0X", 2))
			i += 2;
		while (str[++i])
		{
			if (ft_ishexa(str[i]))
				return (sign * ft_calc(str, i, base));
			if (str[i] == '-' || str[i] == '+')
			{
				if (!ft_ishexa(str[i + 1]))
					return (0);
				sign = 44 - str[i];
			}
			else if (!ft_is_space(str[i]))
				return (0);
		}
	}
	return (0);
}
