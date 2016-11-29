/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 16:05:49 by lgatibel         ###   ########.fr       */
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

t_object		*manage_line(char *line)
{
	t_object *object;

	line = NULL;
	object = NULL;
	return (object);
}

void			parse_file(char *file, t_env **env, t_object **object)
{
	int			fd;
	char		*line;
	t_object	*obj;

	fd = -8;
	line = NULL;
	*object = NULL;

	file = NULL;
/*	if ((fd = open(file, O_RDONLY)) > 0)
		error(OPEN, __LINE__, __FILE__);
	while((get_next(fd, &line)) > 0)
	{
		if (!manage_line(line, object))
			error(INIT, __LINE__, __FILE__ );
	}
	if (close(fd) == -1)
		error(CLOSE, __LINE__, __FILE__);
*/	set_env(env);
	set_object(&obj);
	(*env)->object = obj;
}
