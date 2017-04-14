/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:41:47 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/17 14:58:15 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			ft_verif_debut(char *s)
{
	int		res;

	res = 0;
	while (s[res] == ' ' || s[res] == '\n' || s[res] == '\t')
		res++;
	return (res);
}

static int			ft_verif_fin(char *s)
{
	int		res;

	res = 0;
	while (s[res])
		res++;
	res--;
	while ((res > 0) && (s[res] == ' ' || s[res] == '\n' || s[res] == '\t'))
		res--;
	if (res != 0)
		return (res + 1);
	return (res);
}

char				*ft_strtrim(char const *s)
{
	char	*res;
	int		deb;
	int		fin;
	int		i;

	i = 0;
	if (!s)
		return ((char *)s);
	deb = ft_verif_debut((char *)s);
	fin = ft_verif_fin((char *)s);
	if (fin <= deb)
		res = malloc(sizeof(char) * (0) + 1);
	else
		res = malloc(sizeof(char) * (fin - deb) + 1);
	if (!res)
		return (NULL);
	while (deb < fin)
	{
		res[i] = (char)s[deb];
		i++;
		deb++;
	}
	res[i] = '\0';
	return (res);
}
