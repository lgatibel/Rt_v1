/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:35:31 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 16:56:01 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int					set_vecteur(char **tab, t_p3d *point)
{
	int		i;
	int		t;

	i = 0;
	t = -1;
	while (tab[++i])
	{
		++t;
		if (i < 4 && ft_strisnum(tab[i]))
			*(&point->x + t) = ft_atod(tab[i]);
		else
		{
			error_parse(__FILE__, "bad argument", __LINE__ - 2);
			return (ERROR);
		}
	}
	return (OK);
}

void				set_cam(t_cam *cam, int fd)
{
	char	*line;
	int		i;
	char	**tab;

	i = -1;
	line = NULL;
	tab = NULL;
	while (++i < 2 && (get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		if ((tab = ft_strsplit(line, ' ')) &&
				!ft_strcmp(tab[0], "		origin"))
			set_vecteur(tab, &cam->pos);
		else if ((tab = ft_strsplit(line, ' ')) &&
				!ft_strcmp(tab[0], "		rot"))
			set_vecteur(tab, &cam->rot);
		else
			err(__FILE__, __LINE__, "bad argument for cam set", EXIT);
	}
}

int					set_color(char **tab, int *color)
{
	if (ft_strishexa(tab[1]))
		*color = ft_atoi_base(tab[1], 16);
	else
		return (ERROR);
	return (OK);
}

int					set_radius(char **tab, double *radius)
{
	if (ft_strisnum(tab[1]))
		*radius = ft_atod(tab[1]);
	else
		return (ERROR);
	return (OK);
}
