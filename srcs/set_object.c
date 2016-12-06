/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:40:46 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 13:35:38 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				set_plane(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_plane		*plane;

	i = -1;
	plane = (t_plane *)malloc(sizeof(t_plane));
	(*obj)->ptr = plane;
	(*obj)->type = PLANE;
	(*obj)->next = NULL;
	// voir pour verif
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		tab = ft_strsplit(env->line, ' ');
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, &plane->pos);
		else if (!ft_strcmp(tab[0], "		norm"))
			ok[i] = set_vecteur(tab, &plane->norm);
		else if (!ft_strcmp(tab[0], "		length"))
			ok[i] = set_radius(tab, &plane->d);
		else if (!ft_strcmp(tab[0], "		color"))
			ok[i] = set_color(tab, &(*obj)->color);
	}
	if (i != 4 || !args_required(ok, 3))
		return (ERROR);
	return(OK);
}

int				set_cylinder(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_cylinder	*cylinder;

	i = -1;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	(*obj)->ptr = cylinder;
	(*obj)->type = CYLINDER;
	(*obj)->next = NULL;
	// voir pour verif
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		tab = ft_strsplit(env->line, ' ');
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, &cylinder->pos);
		else if (!ft_strcmp(tab[0], "		rot"))
			ok[i] = set_vecteur(tab, &cylinder->rot);
		else if (!ft_strcmp(tab[0], "		radius"))
			ok[i] = set_radius(tab, &cylinder->radius);
		else if (!ft_strcmp(tab[0], "		color"))
			ok[i] = set_color(tab, &(*obj)->color);
	}
	if (i != 4 || !args_required(ok, 4))
		return (ERROR);
	return(OK);
}

int				set_sphere(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_sphere	*sphere;

	i = -1;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(*obj)->ptr = sphere;
	(*obj)->type = SPHERE;
	(*obj)->next = NULL;
	// voir pour verif
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		tab = ft_strsplit(env->line, ' ');
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, &sphere->pos);
		else if (!ft_strcmp(tab[0], "		rot"))
			ok[i] = set_vecteur(tab, &sphere->rot);
		else if (!ft_strcmp(tab[0], "		radius"))
			ok[i] = set_radius(tab, &sphere->radius);
		else if (!ft_strcmp(tab[0], "		color"))
			ok[i] = set_color(tab, &(*obj)->color);
	}
	if (i != 4 || !args_required(ok, 4))
		return (ERROR);
	return(OK);
}

int				set_cone(t_env *env, int fd, t_object **obj)
{
	int		i;
	char	**tab;
	char	ok[5];
	t_cone	*cone;

	i = -1;
	cone = (t_cone *)malloc(sizeof(t_cone));
	(*obj)->ptr = cone;
	(*obj)->type = CONE;
	(*obj)->next = NULL;
	// voir pour verif
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		tab = ft_strsplit(env->line, ' ');
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, &cone->pos);
		else if (!ft_strcmp(tab[0], "		rot"))
			ok[i] = set_vecteur(tab, &cone->rot);
		else if (!ft_strcmp(tab[0], "		radius"))
			ok[i] = set_radius(tab, &cone->radius);
		else if (!ft_strcmp(tab[0], "		color"))
			ok[i] = set_color(tab, &(*obj)->color);
	}
	if (i != 4 || !args_required(ok, 4))
		return (ERROR);
	return(OK);
}

int				handle_object(t_env *env, int fd, t_object **object)
{
	int			i;
	char		**tab;
	t_object	*obj;

	i = -1;
	tab = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	*object = obj;
	while (get_next_line(fd, &env->line) > 0 && ft_strcmp(env->line, "###END"))
	{
		if (++i > 0 && !(obj->next = (t_object *)malloc(sizeof(t_object))))
			error(INIT, __LINE__, __FILE__, EXIT);
		else if (i > 0)
			obj = obj->next;
		ft_putendl(env->line);
		if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	#CONE"))
			set_cone(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	#CYLINDER"))
			set_cylinder(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	#PLANE"))
			set_plane(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	#SPHERE"))
			set_sphere(env, fd, &obj);
		else
			return (ERROR);
	}
	return (OK);
}
