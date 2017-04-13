/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_annexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:35:31 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/12 10:23:59 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int					set_radius(char **tab, double *radius)
{
	if (tab[0] && !tab[1] && ft_strisnum(tab[0]))
		*radius = ft_atod(tab[0]);
	else
		return (ERROR);
	return (OK);
}

int					set_color(char **tab, int *color)
{
	if (tab[0] && !tab[1] && ft_strishexa(tab[0]))
		*color = ft_atoi_base(tab[0], 16);
	else
		return (ERROR);
	return (OK);
}
