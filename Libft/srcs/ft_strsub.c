/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:22:24 by lgatibel          #+#    #+#             */
/*   Updated: 2016/03/11 13:58:01 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return ((char *)s);
	res = malloc(sizeof(char) * (len + 1));
	if (res && len && ((size_t)start + len <= ft_strlen(s)))
	{
		while (i < len)
		{
			res[i] = s[start];
			start++;
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
