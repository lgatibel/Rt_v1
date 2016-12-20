/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/20 14:15:59 by lgatibel         ###   ########.fr       */
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
	t_p3d		rdir;

	cpy_tp3d(&rdir, ray->dir);
	pl = (t_plane *)object->ptr;

	t = -(pl->norm.x * (ray->pos.x - pl->pos.x) + pl->norm.y *
		(ray->pos.y - pl->pos.y) + pl->norm.z * (ray->pos.z - pl->pos.z) +
		pl->d) / (pl->norm.x * rdir.x + pl->norm.y * rdir.y +
			pl->norm.z * rdir.z);
	// faire gaffe a floting point execption
	return ((t < 0) ? -8 : t);
}

double				calc_cone(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cone		*co;
	t_p3d		rdir;

	cpy_tp3d(&rdir, ray->dir);
	co = (t_cone *)object->ptr;
	a = rdir.x * rdir.x + rdir.z *
	rdir.z - rdir.y * rdir.y;
	b = 2 * (rdir.x * (ray->pos.x - co->pos.x) +
	rdir.z * (ray->pos.z - co->pos.z) - rdir.y *
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
	t_p3d		rdir;

	cpy_tp3d(&rdir, ray->dir);
	cyl = (t_cylinder *)object->ptr;
	a = rdir.x * rdir.x + rdir.z * rdir.z;
	b = 2 * (rdir.x * (ray->pos.x - cyl->pos.x) +
	rdir.z * (ray->pos.z - cyl->pos.z));
	c = ((ray->pos.x - cyl->pos.x) * (ray->pos.x - cyl->pos.x) +
	(ray->pos.z - cyl->pos.z) * (ray->pos.z - cyl->pos.z)) -
	cyl->radius * cyl->radius;
	return (calc_delta(a, b, c));
}

/////////////////////////////////////////////voir pour les martice de translation
//	set_tp3d(&pos, cyl->pos.x, cyl->pos.y, cyl->pos.z);
	//rotation sur z
//	ray->dir.x *= cyl->pos.x;
//	ray->dir.y *= cyl->pos.y;
//	rdir.x = ray->dir.x * cos(cyl->rot.z) + ray->dir.y * -sin(cyl->rot.z);
//	rdir.y = ray->dir.x * sin(cyl->rot.z) + ray->dir.y * cos(cyl->rot.z);
	//
	//rotation sur ++++y
//	rdir.x = ray->dir.x * cos(Y) + ray->dir.z * sin(Y);
//	rdir.z = ray->dir.x * -sin(Y) + ray->dir.z * cos(Y);
	//
	//rotation sur x
//	rdir.y = ray->dir.y * cos(X) + ray->dir.z * -sin(X);
//	rdir.z = ray->dir.y * sin(X) + ray->dir.z * cos(X);
	//
//	ray->diri.z = ray->dirz * cos(45) + ray->dir.z * sin(45);

double				calc_sphere(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*s;
	t_p3d		rdir;

	s = (t_sphere *)object->ptr;
	cpy_tp3d(&rdir, ray->dir);
	a = rdir.x * rdir.x + rdir.y *
	rdir.y + rdir.z * rdir.z;
	b = 2 * (rdir.x * (ray->pos.x - s->pos.x) +
	rdir.y * (ray->pos.y - s->pos.y) + rdir.z *
	(ray->pos.z - s->pos.z));
	c = ((ray->pos.x - s->pos.x) * (ray->pos.x - s->pos.x) +
	(ray->pos.y - s->pos.y) * (ray->pos.y - s->pos.y) +
	(ray->pos.z - s->pos.z) * (ray->pos.z - s->pos.z)) -
	s->radius * s->radius;
	return (calc_delta(a, b, c));
}
