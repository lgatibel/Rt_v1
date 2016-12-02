/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/01 18:00:18 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double				calc_delta(double a, double b, double c)
{
	double	t0;
	double	t1;
	double	t;

	if ((b * b) - (4 * a * c) < 0)
		return (0);
	t0 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	t = (t0 > 0 && (t0 < t1 || t1 <= 0)) ? t0 : t1;
	t = (t > 0) ? t : -8;
	return (t);
}

double				calc_plane(t_object *object, t_ray *ray)
{
	t_plane		*pl;
	double		t;

	pl = (t_plane *)object->ptr;
	t = -(pl->norm.x * (ray->pos.x - pl->pos.x) + pl->norm.y *
		(ray->pos.y - pl->pos.y) + pl->norm.z * (ray->pos.z - pl->pos.z) +
		pl->d) / (pl->norm.x * ray->dir.x + pl->norm.y * ray->dir.y +
			pl->norm.z * ray->dir.z);
	// faire gaffe a floting point execption
	return ((t < 0) ? -8 : t);
}

double				calc_cone(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cone		*co;

	co = (t_cone *)object->ptr;
	a = ray->dir.x * ray->dir.x + ray->dir.z *
	ray->dir.z - ray->dir.y * ray->dir.y;
	b = 2 * (ray->dir.x * (ray->pos.x - co->pos.x) +
	ray->dir.z * (ray->pos.z - co->pos.z) - ray->dir.y *
	(ray->pos.y - co->pos.y)) - co->radius * co->radius;
	c = ((ray->pos.x - co->pos.x) * (ray->pos.x - co->pos.x) +
	(ray->pos.z - co->pos.z) * (ray->pos.z - co->pos.z) -
	(ray->pos.y - co->pos.y) * (ray->pos.y - co->pos.y));
	return (calc_delta(a, b, c));
}

double				calc_cylinder(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)object->ptr;
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - cyl->pos.x) +
	ray->dir.z * (ray->pos.z - cyl->pos.z));
	c = ((ray->pos.x - cyl->pos.x) * (ray->pos.x - cyl->pos.x) +
	(ray->pos.z - cyl->pos.z) * (ray->pos.z - cyl->pos.z)) -
	cyl->radius * cyl->radius;
	return (calc_delta(a, b, c));
}

double				calc_sphere(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;

	s = (t_sphere *)object->ptr;
	a = ray->dir.x * ray->dir.x + ray->dir.y *
	ray->dir.y + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->pos.x) +
	ray->dir.y * (ray->pos.y - s->pos.y) + ray->dir.z *
	(ray->pos.z - s->pos.z));
	c = ((ray->pos.x - s->pos.x) * (ray->pos.x - s->pos.x) +
	(ray->pos.y - s->pos.y) * (ray->pos.y - s->pos.y) +
	(ray->pos.z - s->pos.z) * (ray->pos.z - s->pos.z)) -
	s->radius * s->radius;
	return (calc_delta(a, b, c));
}
