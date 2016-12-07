/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/07 10:26:52 by lgatibel         ###   ########.fr       */
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
	while (++i < nb)
	{
		if (!ok[i] || ok[i] == 0)
			return (0);
	}
	return (1);
}

////////////////////////////tester le null dans ft_strcmp/////////////////////

void				manage_parameter(int fd, t_env *env)
{
	int		i;

	i = -1;
	while (++i < 2 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (i == 0 && !ft_strcmp(env->line, "	##CAM"))
			set_cam(&env->cam, fd);
		else if (i == 1 && !ft_strcmp(env->line, "	##OBJECT"))
		{
			set_object(env, fd, &env->object);
			ft_putendl(env->line);
			if (ft_strcmp(env->line, "###END"))
				err(__FILE__, __LINE__, "No [###END] defined", EXIT);
		}
		else
			break ;
	}
	if (i == 0)
		err(__FILE__, __LINE__, "Cam must be defined below start", EXIT);
	if (i == 1)
		err(__FILE__, __LINE__,
				"##OBJECT must be defined below cam arguments", EXIT);
}

static int			good_extension(char *file)
{
	int		length;

	length = 0;
	if ((length = ft_strlen(file)) >= 5)
		if (ft_strcmp(&file[length - 5], ".rtv1"))
			return (ERROR);
	return (OK);
}

void				handle_error(int index, int fd, t_env *env)
{
	if (!index)
		err(__FILE__, __LINE__, "No [###START] defined", EXIT);
	if (close(fd) == -1)
		err(__FILE__, __LINE__, "Close error", NO_EXIT);
	if (!env->object)
		err(__FILE__, __LINE__, "No object set", NO_EXIT);
}

t_object			*parse_file(char *file, t_env *env)
{
	int			fd;
	int			index;

	index = 0;
	set_env(env);
	if (!good_extension(file))
		error_extension(".rtv1", EXIT);
	if ((fd = open(file, O_RDONLY)) < 1)
		error(OPEN, __LINE__, __FILE__, EXIT);
	while ((get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (!strcmp(env->line, "###START") && ++index)
			manage_parameter(fd, env);
	}
	handle_error(index, fd, env);
	set_viewplane(env);
	return (env->object);
}
