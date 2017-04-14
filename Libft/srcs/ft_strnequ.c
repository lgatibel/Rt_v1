/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:51:24 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 11:42:28 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i1;
	size_t res;

	i1 = 0;
	res = 0;
	if (s1 && s2)
	{
		if (!n)
			return (1);
		while ((s1[i1]) && (s2[i1]) && (i1 < n - 1))
		{
			if (s1[i1] == s2[i1])
				res++;
			i1++;
		}
		if (i1 == res && s1[i1] == s2[i1])
			return (1);
	}
	return (0);
}
