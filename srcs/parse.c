/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:44:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/24 12:17:00 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				test(t_env	*env)
{
	env->i = (env->i > 0xFFFFF0)? 0 : env->i + 1000;
//	printf("i = %d\n",env->i);
//	*(env->img_addr + 800 + (450 * env->size_line) / 4) = 0xFFFFFF - env->i;
//	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 10, 5, 0xFFFFFF - env->i, "Rt_v1");
	//its working the refresh
	return (0);
}

void				parse_file(char *file,t_env **env, t_object **object)
{
	int		fd;
	char	*line;
	t_object	*obj;

	fd = -8;
	line = NULL;
	*object = NULL;
	file = "lol"; // a supprimer
/*
	if ((fd = open(file, O_RDONLY)) > 0)
		error(OPEN, __LINE__, __FILE__);
	while((get_next(fd, &line)) > 0)
	{
	}
	if (close(fd) == -1)
		error(CLOSE, __LINE__, __FILE__);
*/
	set_env(env);
	set_object(&obj);
	(*env)->object = obj;
}
