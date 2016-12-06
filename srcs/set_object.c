/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:40:46 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 18:45:17 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void			set_plane(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_plane		*plane;

	i = -1;
	plane = (t_plane *)malloc(sizeof(t_plane));
	(*obj)->ptr = plane;
	(*obj)->type = PLANE;
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0 &&
			(tab = ft_strsplit(env->line, ' ')))
	{
		print_line(&env->line);
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, &plane->pos);
		else if (!ft_strcmp(tab[0], "		norm"))
			ok[i] = set_vecteur(tab, &plane->norm);
		else if (!ft_strcmp(tab[0], "		length"))
			ok[i] = set_radius(tab, &plane->d);
		else if (!ft_strcmp(tab[0], "		color"))
			ok[i] = set_color(tab, &(*obj)->color);
	}
	if (i != 4 || !args_required(ok, 4))
		err(__FILE__, __LINE__, "bad parameter", EXIT);
}

static void			set_cylinder(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_cylinder	*cylinder;

	i = -1;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	(*obj)->ptr = cylinder;
	(*obj)->type = CYLINDER;
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0 &&
			(tab = ft_strsplit(env->line, ' ')))
	{
		print_line(&env->line);
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
		err(__FILE__, __LINE__, "bad parameter", EXIT);
}

static void			set_sphere(t_env *env, int fd, t_object **obj)
{
	int			i;
	char		**tab;
	char		ok[5];
	t_sphere	*sphere;

	i = -1;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(*obj)->ptr = sphere;
	(*obj)->type = SPHERE;
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0 &&
			(tab = ft_strsplit(env->line, ' ')))
	{
		print_line(&env->line);
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
		err(__FILE__, __LINE__, "bad parameter", EXIT);
}

static void			set_cone(t_env *env, int fd, t_object **obj)
{
	int		i;
	char	**tab;
	char	ok[5];
	t_cone	*cone;

	i = -1;
	cone = (t_cone *)malloc(sizeof(t_cone));
	(*obj)->ptr = cone;
	(*obj)->type = CONE;
	ft_bzero(&ok, 5);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0 &&
			(tab = ft_strsplit(env->line, ' ')))
	{
		print_line(&env->line);
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
		err(__FILE__, __LINE__, "bad parameter", EXIT);
}

void				set_object(t_env *env, int fd, t_object **object)
{
	int			i;
	char		**tab;
	t_object	*obj;

	i = -1;
	while (get_next_line(fd, &env->line) > 0 && ft_strcmp(env->line, "###END"))
	{
		ft_putendl(env->line);
		malloc_object(&obj, object, ++i);
		if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(*tab, "	#CONE"))
			set_cone(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) &&
				!ft_strcmp(*tab, "	#CYLINDER"))
			set_cylinder(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) &&
				!ft_strcmp(*tab, "	#PLANE"))
			set_plane(env, fd, &obj);
		else if ((tab = ft_strsplit(env->line, ' ')) &&
				!ft_strcmp(*tab, "	#SPHERE"))
			set_sphere(env, fd, &obj);
		else
			err(__FILE__, __LINE__, "bad parameter for object set", EXIT);
	}
}
// probleme avec trop de pareametre ca fonctionne
