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
/*	double	xindent;
	double	yindent;
	int		x;
	int		y;

	xindent = env->viewplane.width / WIDTH;
	yindent = env->viewplane.height / HEIGHT;
	x = 0;
	y = 0;*/
	t_point		*dir;
	t_point		*o;
	t_sphere	*s;
	double		a;
	double		b;
	double		c;

	dir = &env->ray.dir;
	o = &env->ray.pos;
	s = (t_sphere *)env->object->ptr;
	a = dir->x * dir->x + dir->y * dir->y +
	dir->z * dir->z;
	b = 2 * (dir->x * (o->x - s->x)) +
	dir->y * (o->y - s->y) + dir->z * (o->z - s->z);
	c = ((o->x - s->x) * (o->x - s->x) +
	(o->y - s->y) + (o->z - s->z)) - s->radius * s->radius;
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
