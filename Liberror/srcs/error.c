/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:31:06 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:22 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liberror.h>

void			error(int error, int line)
{
	if (error != 0)
	{
		if (error = MALLOC)
			ft_putstr_fd("malloc erro at line", 2);

		ft_putnbr_fd(line, 2);
	}
}
