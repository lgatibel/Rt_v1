/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:26:50 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/07 12:32:48 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strisnum(char *str)
{
	int		i;
	int		dot;

	i = -1;
	dot = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i + 1] == '\0')
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
		{
			if (!dot && str[i] == '.')
			{
				dot = 1;
				++i;
			}
			else
				return (0);
		}
	return (1);
}
