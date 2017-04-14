/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:07:29 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 12:50:34 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnstr(char const *s, int n)
{
	int length;

	if (s && ((length = ft_strlen(s)) >= n))
		write(1, s, n);
	else if (s)
		write(1, s, length);
}
