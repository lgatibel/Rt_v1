/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:31:53 by lgatibel          #+#    #+#             */
/*   Updated: 2017/02/09 17:18:11 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

#define DEBUG_1 1

double				calc_delta(double a, double b, double c)
{
	double	t0;
	double	t1;
	double	t;
	double	delta;

	if ((delta = (b * b) - (4.0f * a * c)) < 0.0f)
		return (0);
	t0 = (-b + sqrt(delta)) / (2.0f * a);
	t1 = (-b - sqrt(delta)) / (2.0f * a);
	t = (t0 < t1) ? t0 : t1;
	t -= t * 0.0000001f;
	return (t);
//voir pour la saisie des argument comme length ci celui-ci
//est set a 0 si il ny as pas de bug ou egale
}

double				calc_plane(t_object *object, t_ray *ray)
{
	t_plane		*pl;
	double		t;
	double		div;

	pl = (t_plane *)object->ptr;
	if ((div = dot_product_tp3d(pl->normal, ray->dir)) == 0.0f)
		return (-8);
	set_offset(object, ray);
	t = -(dot_product_tp3d(pl->normal, object->offset) + pl->d) / div;
	return ((t < 0) ? -8 : t);
}

double				calc_cone(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		tanj;
	t_cone		*co;

	co = (t_cone *)object->ptr;
	tanj = 1.0f + tan(co->radius / 2.0f * ((double)M_PI / 180.0f)) *
	tan(co->radius / 2.0f * ((double)M_PI / 180.0f));
	set_offset(object, ray);
	a = dot_product_tp3d(ray->dir, ray->dir) - tanj *
	dot_product_tp3d(ray->dir, object->rot) *
	dot_product_tp3d(ray->dir, object->rot);
	b = 2.0f * (dot_product_tp3d(ray->dir, object->offset) - tanj *
	dot_product_tp3d(ray->dir, object->rot) *
	dot_product_tp3d(object->offset, object->rot));
	c = dot_product_tp3d(object->offset, object->offset) - tanj *
	dot_product_tp3d(object->offset, object->rot) *
	dot_product_tp3d(object->offset, object->rot);
	return (calc_delta(a, b, c));
}

double				calc_cylinder(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;
	t_p3d		rdir;

	cyl = (t_cylinder *)object->ptr;
	rdir = rotate_tp3d(&ray->dir, &cyl->rot);
	set_offset(object, ray);
	a = dot_product_tp3d(rdir, rdir) -
	dot_product_tp3d(rdir, object->rot) *
	dot_product_tp3d(rdir, object->rot);
	b = 2.0f * (dot_product_tp3d(rdir, object->offset) -
	dot_product_tp3d(rdir, object->rot) *
	dot_product_tp3d(object->offset, object->rot));
	c = dot_product_tp3d(object->offset, object->offset) -
	dot_product_tp3d(object->offset, object->rot) *
	dot_product_tp3d(object->offset, object->rot) -
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
	set_offset(object, ray);
	a = dot_product_tp3d(ray->dir, ray->dir);
	b = 2 * dot_product_tp3d(ray->dir, object->offset);
	c = dot_product_tp3d(object->offset, object->offset) - s->radius *
	s->radius;
	return (calc_delta(a, b, c));
}
