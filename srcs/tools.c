/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 12:26:01 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
/*
void				calc_t(double a, double b, double c)
{
}
*/
double				calc_cylinder(t_object *object, double *t0, double *t1,
t_env **env)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*s;
	t_ray		*ray;

	s = (t_cylinder *)object->ptr;
	ray = (t_ray *)&(*env)->ray;
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->x) + ray->dir.z *
	(ray->pos.z - s->z));
	c = ((ray->pos.x - s->x) * (ray->pos.x - s->x) + (ray->pos.z - s->z) *
		(ray->pos.z - s->z)) - s->radius * 1;//* s->radius;
	*t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);

	(*env)->t = ((*t0 > 0 && *t0 < (*env)->t) || ((*env)->t == -1)) ? *t0 : (*env)->t;
	(*env)->t = (*t1 > 0 && *t1 < (*env)->t) ? *t1 : (*env)->t;
	//env->t = (*t0 < *t1) ? *t0 : *t1;
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
	a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
		ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->x) + ray->dir.y *
	(ray->pos.y - s->y) + ray->dir.z * (ray->pos.z - s->z));
	c = ((ray->pos.x - s->x) * (ray->pos.x - s->x) + (ray->pos.y - s->y) *
		(ray->pos.y - s->y) + (ray->pos.z - s->z) * (ray->pos.z - s->z)) -
		s->radius * 1;//\* s->radius;
	*t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	*t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	(*env)->t = ((*t0 > 0 && *t0 < (*env)->t) || ((*env)->t == -1)) ? *t0 : (*env)->t;
	(*env)->t = (*t1 > 0 && *t1 < (*env)->t) ? *t1 : (*env)->t;
	//env->t = (*t0 < *t1) ? *t0 : *t1;
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
