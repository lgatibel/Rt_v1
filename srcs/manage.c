/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:12:16 by lgatibel          #+#    #+#             */
/*   Updated: 2017/04/13 17:12:17 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static int			manage_tags(t_env *env, int fd, int i)
{
	if (i == 0 && !ft_strcmp(ft_strtrim(env->line), "##CAM"))
		set_cam(&env->cam, fd);
	else if (i == 1 && !ft_strcmp(ft_strtrim(env->line), "##SPOT"))
		set_spot(&env->light, fd);
	else if (i == 2 && !ft_strcmp(ft_strtrim(env->line), "##OBJECT"))
	{
		set_object(env, fd, &env->object);
		ft_putendl(env->line);
		if (ft_strcmp(ft_strtrim(env->line), "###END"))
			err(__FILE__, __LINE__, "No [###END] defined", EXIT);
	}
	else
		return (0);
	return (1);
}

void				manage_parameter(int fd, t_env *env)
{
	int		i;

	i = -1;
	while (++i < 3 && (get_next_line(fd, &env->line)) > 0)
	{
		ft_putendl(env->line);
		if (!manage_tags(env, fd, i))
			break ;
	}
	if (i == 0)
		err(__FILE__, __LINE__,
		"Cam must be defined below start and only 1 is required", EXIT);
	if (i == 1)
		err(__FILE__, __LINE__,
		"##SPOT must be defined below cam arguments and only 1 is required",
		EXIT);
	if (i == 2)
		err(__FILE__, __LINE__,
		"##OBJECT must be defined below spot arguments and only 1 is required",
		EXIT);
}
