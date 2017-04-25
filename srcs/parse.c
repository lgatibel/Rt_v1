/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2017/01/23 14:38:32 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int					args_required(char *ok, int nb)
{
	int		i;

	i = -1;
	while (++i < nb)
	{
		if (!ok[i])
			return (0);
	}
	return (1);
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
		err(__FILE__, __LINE__, "No object set", EXIT);
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
		if (!strcmp(ft_strtrim(env->line), "###START") && ++index)
			manage_parameter(fd, env);
	}
	handle_error(index, fd, env);
	return (env->object);
}
