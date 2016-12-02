/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/01 18:02:31 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				test(t_env *env)
{
	env->i = (env->i > 0xFFFFF0) ? 0 : env->i + 1000;
	mlx_string_put(env->mlx, env->win, 10, 5, 0xFFFFFF - env->i,
			"Rt_v1");
	return (0);
}

int			set_vecteur(char **tab, t_p3d *point)
{
	int		i;
	int 	t;

	i = 0;
	t = -1;
	while (tab[++i])
	{
		++t;
		if (i < 3 && ft_strisnum(tab[i]))
			*(&point->x + t) = ft_atod(tab[i]);
		else
		{
			error_parse(__FILE__, "bad argument", __LINE__ - 2);
			return (0);
		}
	}
	return (1);
	printf("x = %f, y = %f, z = %f\n",point->x, point->y, point->z);
}

int				handle_cam(t_cam *cam, int fd)
{
	char	*line;
	int		i;
	char	**tab;

	i = -1;
	line = NULL;
	tab = NULL;
	while ((get_next_line(fd, &line)) > 0 && ++i < 2)
	{
		ft_putendl(line);
		if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "		origin"))
			set_vecteur(tab, &cam->pos);
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "		rot"))
			set_vecteur(tab, &cam->rot);
		else
			return (ERROR);
	}
	return (OK);
}
/*
int				set_cone1(t_env *env, int fd)
{
	char	*line;
	int		i;
	char	**tab;

	i = 0;
	while ((get_next_line(fd, &line)) > 0 && ++i < 5)
	{
		tab = ft_strsplit(line);
		if (!ft_strcmp(tab[0], "		origin"))
//		else if (!ft_strcmp(tab[0], "		pos"))
		else
			return (ERROR);
	}
	return (OK);
}*/
int				set_cone1(t_env *env, int fd)
{
	int		i;
	char	**tab;
	char	ok[5];
	t_object	*obj;

	i = 0;

	ft_bzero(&ok, 5);
	while ((get_next_line(fd, &env->line)) > 0 && i <4)
	{
		tab = ft_strsplit(env->line, ' ');
		if (!ft_strcmp(tab[0], "		origin"))
			ok[i] = set_vecteur(tab, obj->ptr.pos);
		else if (!ft_strcmp(tab[0], "		rot"))
			ok[i] = set_vecteur(tab, obj->ptr.rot);
		else if (!ft_strcmp(tab[0], "		rot"))
			ok[i] = set_vecteur(tab, obj->ptr.);
		else if (!ft_strcmp(tab[0], "		radius"))
			ok[i] = set_vecteur(tab, obj->ptr.rot);
	}
	if (!args_required(ok) && i != 4)
		return (ERROR);
	return(0);
}
////////////////////////////tester le null dans ft_strcmp/////////////////////
int				handle_object(t_env *env, int fd)
{
	int		i;
	char	**tab;

	i =fd = env->cam.pos.x;
	i = -1;
	tab = NULL;
	if (env->obj = (t_object *)malloc(sizeof(t_object)))
		error(INIT, __LINE__, __FILE__, EXIT);
	while ((get_next_line(fd, &env->line)) > 0 && !ft_strcmp(env->line, "###END"))
	{
		ft_putendl(env->line);
		if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	CONE"))
			set_cone1(obj , fd , CONE);
			//set_cone1(env, fd);
/*		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "	#CYLINDER"))
			set_vecteur(tab, &cam->rot);
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "	#PLANE"))
			set_vecteur(tab, &cam->rot);
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "	#SPHERE"))
			set_vecteur(tab, &cam->rot);
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "###END"))
			return (END);
		else
			return (ERROR);

	*/}
	return (OK);
}

int				manage_parameter(int *index, int fd, t_env *env)
{
	char	*line;
	int		error;
	int		i;

	line = NULL;
	i = -1;
	while ((get_next_line(fd, &env->line)) > 0 && ++i < 2)
	{
		ft_putendl(env->line);
		if (i == 0 && !ft_strcmp(env->line, "	##CAM"))
			error = handle_cam(&env->cam, fd);
		else if (i == 1 && !ft_strcmp(env->line, "	##OBJECT"))
			error = handle_object(env, fd);
		else
			break;
	}
	if (i != 2)
		error_parse(__FILE__, "Cam must be defined below start", *index++);
	return (1);
}

static int		good_extension(char * file)
{
	int		length;

	length = 0;
	if ((length = ft_strlen(file)) >= 5)
		if (!ft_strcmp(&file[length - 5], ".rtv1"))
			return (1);
	return (0);
}

t_object		*parse_file(char *file, t_env *env)
{
	int			fd;
	int			index;
	t_object	*obj;

	env->line = NULL;
	obj = NULL;
	index = 0;
	if (!good_extension(file))
		error_extension(".rtv1", EXIT);
	if ((fd = open(file, O_RDONLY)) < 1)
		error(OPEN, __LINE__, __FILE__, EXIT);
	while((get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (++index && !strcmp(env->line, "###START"))
			manage_parameter(&index, fd, env);
	}
	if (close(fd) == -1)
		error(CLOSE, __LINE__, __FILE__, NO_EXIT);
	if (!obj)
		printf("test");
//		error(INIT, __LINE__, __FILE__, EXIT);
	set_object(&env->object);
		printf("pos x = %f, y = %f, z = %f\n",
		env->cam.pos.x, env->cam.pos.y,
		env->cam.pos.z);
		printf("rot x = %f, y = %f, z = %f\n",
		env->cam.rot.x, env->cam.rot.y,
		env->cam.rot.z);
	set_env(env);
//	(*env)->object = obj;
	return (obj);
}
