/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/25 16:27:09 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double					calc_delta(double a, double b, double c)
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
//	normalized(&(*env)->ray.dir);
	t = -(pl->a * (ray->pos.x - pl->x) + pl->b * (ray->pos.y- pl->y) + pl->c *
		(ray->pos.z - pl->z) + pl->d) /(pl->a * ray->dir.x + pl->b * ray->dir.y + pl->c *
			ray->dir.z);
	// faire gaffe a floting point execption
	return((t < 0) ? -8 : t);//2000000;
}

double				calc_cone(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cone		*co;

	co = (t_cone *)object->ptr;
//	normalized(&(*env)->ray.dir);
	a = ray->dir.x * ray->dir.x + ray->dir.z *
	ray->dir.z - ray->dir.y * ray->dir.y;
	b = 2 * (ray->dir.x * (ray->pos.x - co->x) +
	ray->dir.z * (ray->pos.z - co->z) - ray->dir.y *
	(ray->pos.y - co->y));
	c = ((ray->pos.x - co->x) * (ray->pos.x - co->x) +
	(ray->pos.z - co->z) * (ray->pos.z - co->z) -
	(ray->pos.y - co->y) * (ray->pos.y - co->y));
	return (calc_delta (a, b, c));
}

double				calc_cylinder(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)object->ptr;
//	normalized(&(*env)->ray.dir);
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - cyl->x) +
	ray->dir.z * (ray->pos.z - cyl->z));
	c = ((ray->pos.x - cyl->x) * (ray->pos.x - cyl->x) +
	(ray->pos.z - cyl->z) * (ray->pos.z - cyl->z)) -
	cyl->radius * cyl->radius;
	return (calc_delta (a, b, c));
}

double				calc_sphere(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;

	s = (t_sphere *)object->ptr;
//	normalized(&(*env)->ray.dir);
	a = ray->dir.x * ray->dir.x + ray->dir.y *
	ray->dir.y + ray->dir.z * ray->dir.z;
	b = 2 * (ray->dir.x * (ray->pos.x - s->x) +
	ray->dir.y * (ray->pos.y - s->y) + ray->dir.z *
	(ray->pos.z - s->z));
	c = ((ray->pos.x - s->x) * (ray->pos.x - s->x) +
	(ray->pos.y - s->y) * (ray->pos.y - s->y) +
	(ray->pos.z - s->z) * (ray->pos.z - s->z)) -
	s->radius * s->radius;
	return (calc_delta (a, b, c));
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
