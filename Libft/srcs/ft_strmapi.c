/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:59:44 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/17 14:31:16 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return ((char *)s);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			res[i] = s[i];
			res[i] = f(i, *(res + i));
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
