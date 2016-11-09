/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/09 17:23:09 by lgatibel         ###   ########.fr       */
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


static void				trace(t_object *object, t_env env)
{
	t_ray		ray;
	int			*img;
	int			i;
	int			j;
	double		t;

	i = 0;
	j = 0;
	t = 1000;
	ray = env.ray;
	normalized(&ray.dir);
	img = (int *)env.img_addr;
	while (j < HEIGHT)
	{
		i = 0;
		ray.pos.y = j;
		ray.pos.x = i;
		while (i < WIDTH)
		{
			if (calc_sphere(object, ray, &t))
			{
				*(img + i + (env.size_line * j) / 4) = BLUE  - BLUE / t;
			printf("t = %f\n",t);
			t = 1000;
			}
			i++;
			ray.pos.x = i;
		}
		j++;
	}
}

int					main(void)
{
	t_env		env;

	env.bpp = 0;
	env.size_line = 0;
	env.endian = 0;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "hello");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img_addr = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);

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
