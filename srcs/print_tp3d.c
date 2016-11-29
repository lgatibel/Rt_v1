/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tp3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:53:26 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 12:05:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

void			print_tp3d(t_p3d *vector)
{
	ft_putendl(ft_lltoa_base(vector->x, 10));
	ft_putendl(ft_lltoa_base(vector->y, 10));
	ft_putendl(ft_lltoa_base(vector->z, 10));
}
