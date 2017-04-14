/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:35:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/02/03 15:15:03 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(s1) + 1);
	if (s1 && res)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = s1[i];
	}
	return (res);
}
