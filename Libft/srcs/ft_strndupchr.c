/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndupchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:37:49 by lgatibel          #+#    #+#             */
/*   Updated: 2016/03/31 15:52:07 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strndupchr(const char c, int size)
{
	char	*res;
	int		i;

	i = -1;
	res = (char *)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		res[i] = c;
	res[i] = '\0';
	return (res);
}
