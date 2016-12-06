/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 16:53:13 by lgatibel         ###   ########.fr       */
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

////////////////////////////tester le null dans ft_strcmp/////////////////////

int				manage_parameter(int *index, int fd, t_env *env)
{
	int		i;

	i = -1;
	while (++i < 2 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (i == 0 && !ft_strcmp(env->line, "	##CAM"))
			set_cam(&env->cam, fd);
		else if (i == 1 && !ft_strcmp(env->line, "	##OBJECT"))
			set_object(env, fd, &env->object);
		else
			return(ERROR);
	}
	if (i == 0)
		err(__FILE__, __LINE__, "Cam must be defined below start", *index++);
	else if (i == 1)
		err(__FILE__, __LINE__, "Object must be defined below camera set",
				*index++);
	return (OK);
}

static int		good_extension(char * file)
{
	int		length;

	length = 0;
	if ((length = ft_strlen(file)) >= 5)
		if (ft_strcmp(&file[length - 5], ".rtv1"))
			return (ERROR);
	return (OK);
}

t_object		*parse_file(char *file, t_env *env)
{
	int			fd;
	int			index;

	index = 0;
	set_env(env);
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
	set_viewplane(env);
	if (close(fd) == -1)
		err(__FILE__,__LINE__, "close error", NO_EXIT);
	if (!env->object)
		err(__FILE__, __LINE__, "object not set", NO_EXIT);
	return (env->object);
}
