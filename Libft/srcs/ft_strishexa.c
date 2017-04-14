/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:55:58 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 09:53:17 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strishexa(char *str)
{
	int		i;

	i = -1;
	if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "0X", 2))
		i += 2;
	while (str[++i])
		if (!ft_ishexa(str[i]))
			return (0);
	return (1);
}
