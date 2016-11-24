/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/24 10:34:29 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				calc_plane(t_object *object, double *t0, double *t1,
t_env **env)
{
/*	double		a;
	double		b;
	double		c;
*/	t_plane		*pl;
	t_ray		*ray;
	double	d;

	d = 1;
	pl = (t_plane *)object->ptr;
	ray = (t_ray *)&(*env)->ray;
	(*env)->t = (pl->x * ray->pos.x + pl->y * ray->pos.y + pl->z *
		ray->pos.z + d) /(pl->x * ray->dir.x + pl->y * ray->dir.y + pl->z *
			ray->dir.z);
	// faire gaffe a floting point execption
	*t0 = *t1;
	//printf("env->t = %f\n",(*env)->t);
	(*env)->t = ((*env)->t < 0) ? -8 : 2000000;//2000000;
	return ((*env)->t);
}

double				calc_cone(t_object *object, double *t0, double *t1,
t_env **env)
{
	double		a;
	double		b;
	double		c;
	t_cone		*co;
	t_ray		*ray;

	co = (t_cone *)object->ptr;
	ray = (t_ray *)&(*env)->ray;
	a = ray->dir.x * ray->dir.x + ray->dir.z *
	ray->dir.z - ray->dir.y * ray->dir.y;
	b = 2 * (ray->dir.x * (ray->pos.x - co->x) +
	ray->dir.z * (ray->pos.z - co->z) - ray->dir.y *
	(ray->pos.y - co->y));
	c = ((ray->pos.x - co->x) * (ray->pos.x - co->x) +
	(ray->pos.z - co->z) * (ray->pos.z - co->z) -
	(ray->pos.y - co->y) * (ray->pos.y - co->y));// - co->radius;
	*t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	(*env)->t = (*t0 >= 0 && *t0 < *t1) ? *t0 : *t1;
	(*env)->t = ((*env)->t >= 0) ? (*env)->t : -8;
	return ((b * b) - (4 * a * c));
}

double				calc_cylinder(t_object *object, double *t0, double *t1,
t_env **env)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;
	t_ray		*ray;

	cyl = (t_cylinder *)object->ptr;
	ray = (t_ray *)&(*env)->ray;
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - cyl->x) +
	ray->dir.z * (ray->pos.z - cyl->z));
	c = ((ray->pos.x - cyl->x) * (ray->pos.x - cyl->x) +
	(ray->pos.z - cyl->z) * (ray->pos.z - cyl->z)) -
	cyl->radius * 1;//* c->radius;
	*t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	(*env)->t = (*t0 >= 0 && *t0 < *t1) ? *t0 : *t1;
	(*env)->t = ((*env)->t >= 0) ? (*env)->t : -8;
	return ((b * b) - (4 * a * c));
}

double				calc_sphere(t_object *object, double *t0, double *t1,
t_env **env)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;
	t_ray		*ray;

	s = (t_sphere *)object->ptr;
	ray = (t_ray *)&(*env)->ray;
	a = ray->dir.x * ray->dir.x + ray->dir.y *
	ray->dir.y + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->x) +
	ray->dir.y * (ray->pos.y - s->y) + ray->dir.z *
	(ray->pos.z - s->z));
	c = ((ray->pos.x - s->x) * (ray->pos.x - s->x) +
	(ray->pos.y - s->y) * (ray->pos.y - s->y) +
	(ray->pos.z - s->z) * (ray->pos.z - s->z)) -
	s->radius * 1;//\* s->radius;
	*t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	(*env)->t = (*t0 >= 0 && *t0 < *t1) ? *t0 : *t1;
	(*env)->t = ((*env)->t >= 0) ? (*env)->t : -8;
	return ((b * b) - (4 * a * c));
}

void				normalized(t_p3d *point)
{
	if (point->x < 0)
		point->x = -point->x;
	if (point->y < 0)
		point->y = -point->y;
	if (point->z < 0)
		point->z = -point->z;
}
