/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:27:52 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/21 15:38:49 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_calc(const char *str, int i)
{
	int n;

	n = 0;
	i -= 1;
	while (ft_isdigit(str[++i]))
		n = (n * 10) + str[i] - 48;
	return (n);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = -1;
	sign = 1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			return (sign * ft_calc(str, i));
		if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			sign = 44 - str[i];
		}
		else if (!ft_is_space(str[i]))
			return (0);
	}
	return (0);
}
