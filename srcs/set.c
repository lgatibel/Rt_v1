/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:35:31 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/12 10:23:59 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int					set_vecteur(char **tab, t_p3d *point)
{
	int		i;
	int		t;

	i = -1;
	t = -1;
	while (tab[++i])
	{
		++t;
		if (i < 3 && tab[i] && ft_strisnum(tab[i]))
			*(&point->x + t) = ft_atod(tab[i]);
		else
			return (ERROR);
	}
	return (i == 3) ? OK : ERROR;
}

int					set_rotation_vecteur(char **tab, t_p3d *point)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (i < 3 && tab[i] && ft_strisnum(tab[i]))
			*(&point->x + i) = (M_PI * ft_atod(tab[i])) / 180;
		else
			return (ERROR);
	}
	return (i == 3) ? OK : ERROR;
}

int					set_vecteur_cam(char **tab, t_p3d *point)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (i < 3 && ft_strisnum(tab[i]))
			*(&point->x + i) = ft_atod(tab[i]);
		else
			return (ERROR);
	}
	return (i == 3) ? OK : ERROR;
}

void				set_cam(t_cam *cam, int fd)
{
	char	*line;
	int		i;
	char	**tab;
	char	ok[2];

	i = -1;
	line = NULL;
	tab = NULL;
	ft_bzero(&ok, 3);
	while (++i < 2 && (get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		if ((tab = ft_strsplit(line, ' ')) &&
				!ft_strcmp(ft_strtrim(tab[0]), "origin"))
			ok[0] = set_vecteur_cam(&tab[1], &cam->pos);
		else if ((tab = ft_strsplit(line, ' ')) &&
				!ft_strcmp(ft_strtrim(tab[0]), "rot"))
			ok[1] = set_rotation_vecteur(&tab[1], &cam->rot);
	}
	if (!args_required(ok, 2))
		err(__FILE__, __LINE__, "bad argument for cam set", EXIT);
}

int					set_color(char **tab, int *color)
{
	if (tab[0] && !tab[1] && ft_strishexa(tab[0]))
		*color = ft_atoi_base(tab[0], 16);
	else
		return (ERROR);
	return (OK);
}
