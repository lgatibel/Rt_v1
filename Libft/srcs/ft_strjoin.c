/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:54:28 by lgatibel          #+#    #+#             */
/*   Updated: 2016/02/05 11:51:59 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ires;
	char	*res;

	i = 0;
	ires = 0;
	if (!s1)
		return ((char *)s1);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (ires < (ft_strlen(s1) + ft_strlen(s2)) + 1)
	{
		if (ires < ft_strlen(s1))
		{
			res[ires] = s1[i];
			if (s1[i + 1] == '\0')
				i = -1;
		}
		else
			res[ires] = s2[i];
		ires++;
		i++;
	}
	return (res);
}
