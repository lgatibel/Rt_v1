/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/05 17:45:10 by lgatibel         ###   ########.fr       */
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
			printf("tab[%d] = %s\n",i,tab[i]);
		if (i < 4 && ft_strisnum(tab[i]))
			*(&point->x + t) = ft_atod(tab[i]);
		else
		{
			printf("tab[%d] = %s\n",i,tab[i]);
			error_parse(__FILE__, "bad argument", __LINE__ - 2);
			return (0);
		}
	}
	return (1);
//	printf("x = %f, y = %f, z = %f\n",point->x, point->y, point->z);
}

int				handle_cam(t_cam *cam, int fd)
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
		if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "		origin"))
			set_vecteur(tab, &cam->pos);
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "		rot"))
			set_vecteur(tab, &cam->rot);
		else
			return (ERROR);
	}
	return (OK);
}

int				set_color(char **tab, int	*color)
{
	if (ft_strishexa(tab[1]))
		*color = ft_atoi_base(tab[1], 16);
	else
		return (0);
	return (1);
}

int				set_radius(char **tab, double *radius)
{
	if (ft_strisnum(tab[1]))
		*radius = ft_atod(tab[1]);
	else
		return (0);
	return (1);
}


int				args_required(char *ok, int nb)
{
	int		i;

	i = -1;
	while (++i < nb && ok[i])
	{
		if (ok[i] == 0)
			return (0);
	}
	return (1);
}

int				set_cone1(t_env *env, int fd, t_object **obj)
{
	int		i;
	char	**tab;
	char	ok[5];
	t_cone	*cone;

	i = -1;
	printf("----cone-----\n");
	cone = (t_cone *)malloc(sizeof(t_cone));
	(*obj)->ptr = cone;
	// voir pour verif
	ft_bzero(&ok, 5);
		printf("???cone line = %s\n",env->line);
	while (++i < 4 && (get_next_line(fd, &env->line)) > 0)
	{
		printf("cone line = %s\n",env->line);
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
	(*obj)->type = CONE;
	(*obj)->next = NULL;
	if (i != 4 || !args_required(ok, 4))
		return (ERROR);
		printf("pos x = %f, y = %f, z = %f\n",cone->pos.x,cone->pos.y,cone->pos.z);
		printf("pos x = %f, y = %f, z = %f\n",cone->rot.x,cone->rot.y,cone->rot.z);
	return(OK);
}
////////////////////////////tester le null dans ft_strcmp/////////////////////
int				handle_object(t_env *env, int fd, t_object **object)
{
	int			i;
	char		**tab;
	t_object	*obj;

	i = -1;
	tab = NULL;
	obj = (t_object *)malloc(sizeof(t_object));
	*object = obj;
	while (get_next_line(fd, &env->line) > 0 && ft_strcmp(env->line, "##END"))
	{
		if (++i > 0 && !obj->next && (obj->next = (t_object *)malloc(sizeof(t_object))))
			error(INIT, __LINE__, __FILE__, EXIT);
		ft_putendl(env->line);
		if ((tab = ft_strsplit(env->line, ' ')) && !ft_strcmp(tab[0], "	#CONE"))
			set_cone1(env, fd, &obj);
//		printf("tab[]  = %s\n", tab[0]);
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
		*/	
	}
	printf("line  = [%s]\n", env->line);
	printf("over, i = %d\n", i);
	return (OK);
}

int				manage_parameter(int *index, int fd, t_env *env)
{
	char	*line;
	int		error;
	int		i;

	line = NULL;
	i = -1;
	error = 0;
	while (++i < 2 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (i == 0 && !ft_strcmp(env->line, "	##CAM"))
			error = handle_cam(&env->cam, fd);
		else if (i == 1 && !ft_strcmp(env->line, "	##OBJECT"))
			error = handle_object(env, fd, &env->object);
		else
			break;
	}
//	handle error;
	if (error)
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

	env->line = NULL;
	index = 0;
	env->object = NULL;
	set_env(env);
//	set_object(&env->object);
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
	if (!env->object)
	{
		printf("object not set");
		error(INIT, __LINE__, __FILE__, NO_EXIT);
	}
	printf("----type  = %d\n", env->object->color);
/*		printf("pos x = %f, y = %f, z = %f\n",
		env->cam.pos.x, env->cam.pos.y,
		env->cam.pos.z);
		printf("rot x = %f, y = %f, z = %f\n",
		env->cam.rot.x, env->cam.rot.y,
		env->cam.rot.z);
*/
	return (env->object);
}
