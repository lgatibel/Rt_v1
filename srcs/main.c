/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 15:19:28 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		trace_test(t_env *env)
{
	int		x;
	int		y;
	double		t0;
	double		t1;
	double		delta;


	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			delta = calc_delta(env, &t0, &t1);
			if (delta >= 0)
			{
				*(env->img_addr + (int)x + ((int)y * env->size_line) / 4) =
					color(GREEN, 1);
			}
		}
		printf("y = %d\n", y);
	}
}



int					main(int ac, char **av)
{
	t_env		*env;
	t_object	*object;

	t_p3d		*test1;
	t_p3d		*test2;
	double		test;
	int			i;

	i = 0;
	test = 0;
	env = NULL;
	test1 = (t_p3d *)malloc(sizeof(t_p3d));
	test2 = (t_p3d *)malloc(sizeof(t_p3d));
	if (ac == 2)
	{
		parse_file(av[1], &env, &object);
		set_ray(&env->ray);
		set_sphere(&env->object);
		trace_test(env);
		//trace(env->object, *env);
		mlx_put_image_to_window(env->mlx, env->win,
				env->img, 0, 0);
		write(1, "finish", 6);
		mlx_hook(env->win, 2, (1L<<0), ft_exit, &env);
		mlx_hook(env->win, 17, (1L<<17), ft_exit, &env);
		mlx_loop(env->mlx);
	}
	else
	{
		test1->x = 1;
		test1->y = 1;
		test1->z = 1;

		test2->x = 2;
		test2->y = 2;
		test2->z = 2;
		test  = tp3d_mult(*test1, *test2);
		*test1  = tp3d_sub(*test1, *test2);
		printf("sub test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		*test1  = tp3d_sum(*test1, *test2);
		printf("sum test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		tp3d_cpy(test1, *test2);
		printf("cpy test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		*test1  = tp3d_mult_nb(*test1, 10);
		printf("nb test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);

	}
	return (0);
}
