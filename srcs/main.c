/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/13 14:39:14 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double		norm(t_p3d *vec)
{
	double res;
	res = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	return (res);
}

double				calc_object(t_object *object, t_env **env, double x ,
		double y)
{
	double		dist;
	double		t;
	t_p3d		ray;
//	double		length;

	t = -1;
	while (object)
	{
		if (object->type == SPHERE)
			dist = calc_sphere(object, &(*env)->ray);
		else if (object->type == CYLINDER)
			dist = calc_cylinder(object, &(*env)->ray);
		else if (object->type == CONE)
			dist  = calc_cone(object, &(*env)->ray);
		else if (object->type == PLANE)
			dist = calc_plane(object, &(*env)->ray);
		if (dist > 0 && ((dist < t) || t == -1))
		{
			(*env)->color = object->color;
			if (t == -1)
				cpy_tp3d(&(*env)->intersect, mult_nb_tp3d(sum_tp3d((*env)->ray.pos,(*env)->ray.dir), dist));
			t = dist;
			// il faudra peut etre calculer la normal du vecteur pour les position 
			// different de zero

			//set_tp3d(&(*env)->intersect, x *  dist, y * dist, dist);
			cpy_tp3d(&ray, mult_nb_tp3d(sum_tp3d((*env)->ray.pos,(*env)->ray.dir), dist));
			if (norm(&ray) < norm(&(*env)->intersect))
				cpy_tp3d(&(*env)->intersect, mult_nb_tp3d(sum_tp3d((*env)->ray.pos,(*env)->ray.dir), dist));
//			printf("x = [%f], y = [%f], z  = [%f]\n",ray.x,ray.y, ray.z );
			x *=1;
			y *=1;
//			if (norm(&ray))
			//pas sur pour les pooint x et y  a voir
//				printf("t= [%f]\n",t);
		}
		object = object->next;
	}
	return (t);
}

void				reverse_tp3d(t_p3d *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}

int					calc_light(t_env *env)
{
	t_light *light;
	//t_p3d	norm;
	double angle;
	int col;
	double coef;

	coef = 0.8;

	light = &env->light;
	light->dir = sub_tp3d(env->intersect, light->pos);
	reverse_tp3d(&light->dir);
//	light->dir = sub_tp3d(light->pos, env->intersect);
	normalized(&light->dir, 1);
	normalized(&env->intersect, 1);
	col = env->color;
	angle = mult_tp3d(env->intersect, light->dir);
//	color = shade;
//	printf("x = [%f], y = [%f], z = [%f]\n",diff.x, diff.y, diff.z);
	//shade = mult_tp3d(diff, one);
//	printf("color = [%d]\n",color);
	
//	return (color);
//	printf("angle = [%f]\n",angle);
	if (angle <= 0)
		col = 0;
	else
	col = ((int)((1 - angle) * env->color * coef)& 0x00FF00) ;//+
//	col = ((int)((1 - angle) * env->color * coef) & 0x00FF00) +
//	 ((int)((1 - angle) * env->color * coef) & 0xFF0000) ;//+
//	 ((int)((1 - angle) * env->color * coef) & 0x0000FF);
//	col = shade * ((color && 0xFF0000) * .2 + (color && 0x00FF00) * 0.2 +
//	printf("color = %d", ((int)((1 - angle) * env->color * coef) & 0x0000FF));
//			(color && 0x0000FF) * 0.2);
//printf("col = [%d]\n",col);
	return (col);
}

void				trace(t_env *env)
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
			if (calc_object(env->object, &env, x, y) >= 0)
			{
				*(env->img_addr + x + (y * env->size_line) / 4) =
				calc_light(env);
				//	color(env->color, 1);
			}
		}
	}
}

int					main(int ac, char **av)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		error(INIT, __LINE__ - 1, __FILE__, EXIT);
	if (ac == 2)
	{
		parse_file(av[1], env);
		set_ray(&env->ray, env);
		set_light(&env->light);
		trace(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		event(env);
		mlx_loop(env->mlx);
	}
	else
		error_arg(1, ac - 1, EXIT);
	return (0);
}
