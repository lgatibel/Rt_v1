/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/16 10:53:05 by lgatibel         ###   ########.fr       */
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

	env->xindent = (float)env->viewplane.width / (float)WIDTH;
	env->yindent = (float)env->viewplane.height / (float)HEIGHT;
	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calc_ray(env, x, y);

			delta = calc_delta(env, &t0, &t1);
			if (delta >= 0)
			{
			//			printf("x = %f,y = %f,z = %f\n",dir->x,dir->y,dir->z);
			if (x >= 100 && x <= 120)
				*(env->img_addr + (LARG + (int)x) + ((HAUT + (int)y) * env->size_line) / 4) = color(WHITE, 1);
/*
			if (delta >= 0 && ((t0 > 0 && t0 < T) ||
						(t1 > 0 && t1 < T)))
			{
*/
				*(env->img_addr + (LARG + (int)x) + ((HAUT + (int)y) * env->size_line) / 4) = color(GREEN, 1);
	//			printf("t0 = %f, t1 = %f\n",t0, t1);
				//printf("t0 = %f, t1 = %f\n",t0,t1);
			}
//			}
			//	printf("delta = %f\n",delta);
			x++;
		}
		y++;
	}

	//	printf("a = %f, b = %f, c = %f, delta = %f\n t0 = %f, t1 = %f\n",a, b, c, delta, t0, t1);

	//	b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))

	//	c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2
}

int					main(int ac, char **av)
{
	t_env		*env;

	t_point		*test1;
	t_point		*test2;
	double		test;

	test = 0;
	env = NULL;
	test1 = (t_point *)malloc(sizeof(t_point));
	test2 = (t_point *)malloc(sizeof(t_point));
	if (ac == 1 && !av[1])
	{
		env = set_env(env);
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
		test  = matrice_mult_1x1(*test1, *test2);
		*test1  = matrice_sub_1x1(*test1, *test2);
		printf("sub test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		*test1  = matrice_sum_1x1(*test1, *test2);
		printf("sum test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		matrice_cpy(test1, *test2);
		printf("cpy test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
		*test1  = matrice_mult_1x1_nb(*test1, 10);
		printf("nb test = %f,testx =  %f,testy = %f,testz = %f\n", test, test1->x, test1->y, test1->z);
	}
	return (0);
}
