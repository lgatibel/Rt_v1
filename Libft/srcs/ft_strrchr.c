/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:37:13 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 11:46:07 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*sres;

	sres = (char *)s;
	i = 0;
	while (s[i])
		i++;
	while (i > -1)
	{
		if (s[i] == (char)c)
			return ((sres + i));
		i--;
	}
	return (NULL);
}
