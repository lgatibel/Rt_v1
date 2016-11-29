/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 17:36:26 by lgatibel         ###   ########.fr       */
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


t_object		*manage_line(char *line, int *index)
{
	t_object *object;

	object = NULL;
	if (*index == 0 && ft_strcmp(line, "###START"))
		error_parse(__FILE__, "no start in file", *index + 1);
	else if (*index == 1 && (ft_strcmp(line, "##CAM") && !set_cam(&object,
			*index)))
		error_parse(__FILE__, "bad camera definition", *index + 1);

	return (object);
}

void			parse_file(char *file, t_env **env, t_object **object)
{
	int			fd;
	int			index;
	char		*line;
	t_object	*obj;
	t_object	*tmp;

	fd = -8;
	line = NULL;
	*object = NULL;

//	file = NULL;
	obj = NULL;
	index = 0;
	if ((fd = open(file, O_RDONLY)) < 1)
		error(OPEN, __LINE__, __FILE__, NO_EXIT);
	while((get_next_line(fd, &line)) > 0)
	{
		manage_line(line, &index);
		if (obj == NULL)
			printf("null\n");
		tmp = obj;
		//*object = manage_line(line, object)
//			error(INIT, __LINE__, __FILE__ );
		index++;
	}
	if (close(fd) == -1)
		error(CLOSE, __LINE__, __FILE__, NO_EXIT);
	set_env(env);
//	set_object(&obj);
	(*env)->object = obj;
}
