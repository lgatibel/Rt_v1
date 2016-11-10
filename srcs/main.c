/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 19:15:47 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>



void				normalized(t_point *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}



int					main(void)
{
	t_env		env;

	env.bpp = 0;
	env.size_line = 0;
	env.endian = 0;

	env.t = 1000;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "hello");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img_addr = (int *)mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);

	set_ray(&env.ray);
	set_sphere(&env.object);
	trace(env.object, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	write(1, "finish", 6);
	mlx_hook(env.win, 2, (1L<<0), ft_exit, &env);
	mlx_hook(env.win, 17, (1L<<17), ft_exit, &env);
	mlx_loop(env.mlx);
	return (0);
}
