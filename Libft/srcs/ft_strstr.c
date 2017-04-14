/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:20:49 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 11:52:33 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] && ft_strlen(s2) != i2)
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
	if (ft_strlen(s2) == i2)
		return ((char*)&(s1[i - i2]));
	return (NULL);
}
