/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:20:04 by lgatibel          #+#    #+#             */
/*   Updated: 2016/03/31 15:50:35 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_cbmots(char *s, char c, int choice)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (choice == 0)
	{
		while (s[i])
		{
			if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			{
				nb++;
			}
			i++;
		}
	}
	else
		while (s[nb] != c && s[nb] != '\0')
		{
			nb++;
		}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return ((char **)s);
	res = (char**)malloc(sizeof(char *) * (ft_cbmots((char *)s, c, 0) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_strsub((char *)s, (unsigned int)i,
				ft_cbmots((char *)(s + i), c, 1));
			i += ft_cbmots((char *)(s + i), c, 1) - 1;
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
