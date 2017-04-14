/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:25:38 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/27 13:14:21 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void			set_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		err(__FILE__, __LINE__, "Error in mlx init fucntion", EXIT);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "hello")))
		err(__FILE__, __LINE__, "Error in mlx init fucntion", EXIT);
	if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		err(__FILE__, __LINE__, "Error in mlx init fucntion", EXIT);
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	if (!(env->img_addr = (int *)mlx_get_data_addr(env->img,
	&env->bpp, &env->size_line, &env->endian)))
		err(__FILE__, __LINE__, "Error in mlx init fucntion", EXIT);
}

void				set_env(t_env *env)
{
	env->basis.x = WIDTH / HEIGHT;
	env->basis.y = 1.0f;
	env->basis.z = 0.0f;
	env->indent.x = env->basis.x / WIDTH;
	env->indent.y = env->basis.y / HEIGHT;
	env->indent.z = 0.0f;
	env->object = NULL;
	env->nearest_object = NULL;
	env->font_color = FONT;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	set_mlx(env);
	env->line = NULL;
	env->t = -1;
	env->i = 0;
}