/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tp3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:53:26 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 15:21:06 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tp3d.h>

void			print_tp3d(t_p3d *vector)
{
	char *str;
	char *tmp;

	str = ft_lltoa_base(vector->x, 10);
	tmp = str;
	str = ft_strjoin(str, ", ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ft_lltoa_base(vector->y, 10));
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ", ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, ft_lltoa_base(vector->z, 10));
	free(tmp);
	ft_putendl(str);
}
