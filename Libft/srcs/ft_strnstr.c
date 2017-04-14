/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:20:49 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/04 20:52:38 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] && i < n && ft_strlen(s2) != i2 &&
			ft_strlen(s1) >= ft_strlen(s2))
	{
		if (s1[i] == s2[i2])
			i2++;
		else
		{
			i -= i2;
			i2 = 0;
		}
		i++;
	}
	if (ft_strlen(s2) == i2 && ft_strlen(s1) >= ft_strlen(s2))
		return ((char*)&(s1[i - i2]));
	return (0);
}
