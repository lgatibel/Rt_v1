/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:03:22 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 12:21:36 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src != dst)
	{
		if (src > dst)
		{
			while (i < len)
			{
				((char *)dst)[i] = ((char *)src)[i];
				i++;
			}
		}
		else
		{
			while (len > 0)
			{
				((char *)dst)[len - 1] = ((char *)src)[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
