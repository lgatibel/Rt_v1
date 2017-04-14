/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:53:42 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 12:24:12 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)s;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			if (*(res + i) == (unsigned char)c)
				return ((void *)(res + i));
			i++;
		}
	}
	res = NULL;
	return ((void *)res);
}
