/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/20 09:35:52 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				reverse_tp3d(t_p3d *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}

double		norm(t_p3d *vec)
{
	double res;
	res = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	return (res);
}

double				calc_norm(t_ray *ray, double t, t_env *env,
		t_object *object)
{

	t_sphere *sphere;
	t_cylinder *cyl;
	t_cone *cone;

	cpy_tp3d(&env->intersect,
		mult_nb_tp3d(
		sum_tp3d(ray->pos,
		ray->dir), t));
		sphere = (t_sphere *)object->ptr;
		env->norm = div_nb_tp3d(sub_tp3d(env->intersect, sphere->pos), sphere->radius);
		if (object->type == CYLINDER || object->type == EXIT)
		{
			cyl = (t_cylinder *)object->ptr;
			env->norm = div_nb_tp3d(sub_tp3d(env->intersect, cyl->pos),
					cyl->radius);
			set_tp3d(&env->norm, env->norm.x, 0, env->norm.z);
		//	printf("--cylindre\n");
		}
		else if (object->type == CONE)
		{
		//	printf("--cone\n");
			cone = (t_cone *)object->ptr;
			env->norm = sub_tp3d(env->intersect, cone->pos);
//			env->norm = div_nb_tp3d(sub_tp3d(env->intersect, cone->pos),cone->radius);
			set_tp3d(&env->norm, 0, env->norm.y, env->norm.z);
		}
	//	reverse_tp3d(&env->norm);
	//	reverse_tp3d(&env->norm);
//	env->norm = sub_tp3d(env->intersect, sphere->pos);
//	printf("test = [%f]\n",env->norm.z);
	return (norm(&env->intersect));
}

double				calc_object(t_object *object, t_env **env)
{
	double		tmp;
	double		t;
	double		length;

	t = -1;
	tmp = -1;
	length = -1;
	int i = 0;//debug
	while (object)
	{
	++i;
		if (object->type == SPHERE)
			t = calc_sphere(object, &(*env)->ray);
		else if (object->type == CYLINDER)
			t = calc_cylinder(object, &(*env)->ray);
		else if (object->type == CONE)
			t  = calc_cone(object, &(*env)->ray);
		else if (object->type == PLANE)
			t = calc_plane(object, &(*env)->ray);
		tmp = calc_norm(&(*env)->ray, t, *env, object);
		if (t >= 0 && tmp > 0 && ((tmp < length) ||
		length == -1))
		{
			(*env)->color = object->color;
			length = tmp;
		}
		object = object->next;
	}
	return (length);
}

int					calc_light(t_env *env)
{
	t_light *light;
	double angle;
	int col;
	double diffuse;

	light = &env->light;
		if (env->intersect.y > 0)
		printf("x[%f], y[%f], z[%f]\n", env->intersect.x, env->intersect.y, env->intersect.z);
	normalized(&env->intersect, 1);
	light->dir = sub_tp3d(env->intersect, light->pos);
//	reverse_tp3d(&light->dir);
	normalized(&light->dir, 1);
	normalized(&env->norm, 1);
	angle = mult_tp3d(env->norm, light->dir);

//	color = shade;
	diffuse = angle * COEFF * 255;
	col = ((int)(color(env->color, RED) * diffuse) << 16) +
	((int)(color(env->color, GREEN) * diffuse) << 8) +
	(int)(color(env->color, BLUE) * diffuse) ;
	return (col);
}

void				trace(t_env *env)
{
	int		x;
	int		y;
	int		length;
	int		color;

	y = -1;
	x = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(env, x, y);
			if ((length = calc_object(env->object, &env)) >= 0)
				color = calc_light(env);
			else
				color = FOND;
			*(env->img_addr + x + (y * env->size_line) / 4) = color;
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
