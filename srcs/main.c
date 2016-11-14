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

static void		trace_test(t_env *env)
{
		double	xindent;
		double	yindent;
		int		x;
		int		y;

	t_point		*dir;
	t_point		*o;
	t_point		*upvec;
	t_point		*rvec;
	t_sphere	*s;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t0;
	double		t1;

	dir = &env->ray.dir;
	o = &env->ray.pos;
	upvec = &env->viewplane.upvec;
	rvec = &env->viewplane.rvec;
	s = (t_sphere *)env->object->ptr;
	xindent = env->viewplane.width / WIDTH;
	yindent = env->viewplane.height / HEIGHT;
	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		x = 0;
		//dir->x = 0;
		while (x < WIDTH)
		{
			matrice_cpy(dir, matrice_sum_1x1(env->viewplane.upleft, matrice_sub_1x1(matrice_mult_1x1_nb(*upvec,x * xindent), matrice_mult_1x1_nb(*rvec, y * yindent))));
			normalized(dir);
//			printf("x = %f,y = %f,z = %f\n",dir->x,dir->y,dir->z);
			a = dir->x * dir->x + dir->y * dir->y +
				dir->z * dir->z;
			b = 2 * (dir->x * (o->x - s->x) +
					dir->y * (o->y - s->y) + dir->z *
					(o->z - s->z));
			c = ((o->x - s->x) * (o->x - s->x) +
				(o->y - s->y) * (o->y - s->y) +
				(o->z - s->z) * (o->z - s->z))
				- s->radius * s->radius;
			delta = (b * b) - (4 * a * c);
			t0 = (-b + sqrt(delta)) / (2 * a);
			t1 = (-b - sqrt(delta)) / (2 * a);
			if (delta >= 0)
			{
			*(env->img_addr + (int)dir->x + ((int)dir->y * env->size_line) / 4) = color(GREEN, 1);
			printf("delta = %f, dirx = %f\n",delta, dir->x);
			}
			x++;
		//	dir->x += 1;
		}
		y++;
		//dir->y += 1;
	}

//	printf("a = %f, b = %f, c = %f, delta = %f\n t0 = %f, t1 = %f\n",a, b, c, delta, t0, t1);

	//	b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))

	//	c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2
}

int					main(void)
{
	t_env		*env;

	env = NULL;
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
	return (0);
}
