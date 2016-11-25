/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 17:32:03 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double			calc_object(t_object *object, t_env **env)
{
	double		dist;
	double		t;

	int			test;


	t = -1;
	test = 1;
	while (object)
	{
		//printf("type = %d\n", object->type);
		if (object->type == SPHERE)
			dist = calc_sphere(object, &(*env)->ray);
		else if (object->type == CYLINDER)
			dist = calc_cylinder(object, &(*env)->ray);
		else if (object->type == CONE)
			dist	 = calc_cone(object, &(*env)->ray);
		else if (object->type == PLANE)
			dist = calc_plane(object, &(*env)->ray);
//		if (dist > 0 && (*env)->t > 0 &&
//				(((*env)->t < t && t > 0) || t == -1))
		if (dist > 0 &&
				((dist < t) || t == -1))
		{
			(*env)->color = object->color;
	//		(*env)->color = (int)onecolor_lerp(object->color, (*ent)->t / (object_>ptr->pos->z - object->ptr->radius));
			t = dist;
		}
		//	printf("t = %f\n",(*env)->t);
		object = object->next;
		test++;
	}
	//printf("test = %d\n",test);
	//
	//	printf("delta = %f, tmp = %f\n",delta, tmp);
	return (t);
}

static void		trace_test(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			if (calc_object(env->object, &env) >= 0)
			{
				*(env->img_addr + x + (y * env->size_line) / 4) =
					color(env->color, 1);
				//	printf("delta = %f\n", delta);
			}
		}
	}
}

void				set_global(t_grtv1 *global)
{
	global->env = NULL;
	global->object = NULL;
	global->ray = NULL;
}

int					main(int ac, char **av)
{
	t_grtv1		global;
	t_env		*env;
	t_object	*object;

	// a voir plus tard si le global est interessant
	set_global(&global);
	object = NULL;
	env = NULL;
	if (ac == 2)
	{
		parse_file(av[1], &env, &object);

		set_ray(&env->ray, &env->cam);
		trace_test(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);
//a suprimer
		write(1, "finish", 6);
		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
/*
size_t			twocolor_lerp(unsigned int a, unsigned int b, const float pc)
{
	t_pos	color;

	if (pc <= 0.0f)
		return (a);
	if (pc >=	 1.0f)
		return (b);
	color.x = (float)(a & 0xff0000) * (1.0f - pc) + (float)(b & 0xff0000) * pc;
	color.y = (float)(a & 0x00ff00) * (1.0f - pc) + (float)(b & 0x00ff00) * pc;
	color.z = (float)(a & 0x0000ff) * (1.0f - pc) + (float)(b & 0x0000ff) * pc;
	return((((unsigned int)color.x) & 0xff0000) |
			(((unsigned int)color.y) & 0x00ff00) |
			(((unsigned int)color.z) & 0x0000ff));
}
*//*
size_t			onecolor_lerp(unsigned int a, const float pc)
{
	int		b;
	int		x;
	int		y;
	int		z;

	b = (a >> 1) & 8355711;
	if (pc <= 0.0f)
		return (a);
	if (pc >= 1.0f)
		return (b);
	x = (float)(a & 0xff0000) * (1.0f - pc) + (float)(b & 0xff0000) * pc;
	y = (float)(a & 0x00ff00) * (1.0f - pc) + (float)(b & 0x00ff00) * pc;
	z = (float)(a & 0x0000ff) * (1.0f - pc) + (float)(b & 0x0000ff) * pc;
	return((((unsigned int)x) & 0xff0000) |
			(((unsigned int)y) & 0x00ff00) |
			(((unsigned int)z) & 0x0000ff));
}*/
// a couleur
// pc pourcentage degrader t / (posz_objs - radius)
