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

void			set_vecteur(char **tab, t_p3d *point)
{
	int		i;
	int 	t;

	i = 0;
	t = -1;
	while (tab[++i])
	{
		++t;
		if (ft_strisnum(tab[i]))
			*(&point->x + t) = ft_atod(tab[i]);
		else
			error_parse(__FILE__, "bad argument", __LINE__ - 2);
	}
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
		{
//			printf("origin ok\n");
			set_vecteur(tab, &cam->pos);
		}
		else if ((tab = ft_strsplit(line, ' ')) && !ft_strcmp(tab[0], "		rot"))
		{
//			printf("rot ok\n");
			set_vecteur(tab, &cam->rot);
		}
		else
			return (0);
	}
	return (1);
}

int				manage_parameter(int *index, int fd, t_env **env,
		t_object **obj)
{
	char	*line;

	t_object *test;
	test = *obj;

	line = NULL;
	get_next_line(fd, &line);
		ft_putendl(line);
	if (!ft_strcmp(line, "	##CAM"))// && !set_cam(&object,*index)))
		handle_cam(&(*env)->cam, fd);
	else if (!ft_strcmp(line, "	OBJECT"))
		
	else
		error_parse(__FILE__, "Cam must be defined below start", *index + 1);
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

t_object		*parse_file(char *file, t_env **env)
{
	int			fd;
	int			index;
	char		*line;
	t_object	*obj;

	line = NULL;
	obj = NULL;
	index = 0;
	if (!good_extension(file))
		error_extension(".rtv1", EXIT);
	if ((fd = open(file, O_RDONLY)) < 1)
		error(OPEN, __LINE__, __FILE__, EXIT);
	while((get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		if (++index && !strcmp(line, "###START"))
			manage_parameter(&index, fd, env, &obj);
	}
	if (close(fd) == -1)
		error(CLOSE, __LINE__, __FILE__, NO_EXIT);
	if (!obj)
		printf("test");
//		error(INIT, __LINE__, __FILE__, EXIT);
	set_object(&(*env)->object);
		printf("pos x = %f, y = %f, z = %f\n",
		(*env)->cam.pos.x, (*env)->cam.pos.y,
		(*env)->cam.pos.z);
		printf("rot x = %f, y = %f, z = %f\n",
		(*env)->cam.rot.x, (*env)->cam.rot.y,
		(*env)->cam.rot.z);
	set_env(env);
//	(*env)->object = obj;
	return (obj);
}
