/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:15:32 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/27 12:39:06 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_str_is_hexa(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 'A' && str[i] > 'F') &&
				(str[i] < 'a' && str[i] > 'f') && !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
