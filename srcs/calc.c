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
	return (t);
}

double				calc_plane(t_object *object, t_ray *ray)
{
	t_plane		*pl;
	double		t;
	double		div;
	t_p3d		rot;

	pl = (t_plane *)object->ptr;
	rot = rotate_tp3d(&object->rot, &pl->normal);
	if ((div = dot_product_tp3d(rot, ray->dir)) == 0.0f)
		return (-8);
	set_offset(object, ray);
	t = -(dot_product_tp3d(rot, object->offset) + pl->d) / div;
	if (!object->set)
	{
		if (div < 0.0f)
			cpy_tp3d(&object->normal, object->rot);
		else
			cpy_tp3d(&object->normal, mult_nb_tp3d(object->rot, -1));
		normalized(&object->rot);
	}
	return ((t < 0) ? -8 : t);
}

static	void		cone_normal(t_ray *ray, t_object *object, t_p3d rot)
{
	t_cone	*cone;
	// t_p3d		rot;
	double		m;

	cone = (t_cone *)object->ptr;

	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	rot = rotate_tp3d(&object->rot, &cone->rot);
	m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	dot_product_tp3d(object->offset, rot);

	object->normal = sub_tp3d(sub_tp3d(object->inter, cone->pos),
	mult_nb_tp3d(rot, m));
	normalized(&object->normal);
}

double				calc_cone(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		tanj;
	t_cone		*co;

	co = (t_cone *)object->ptr;
	object->rot = rotate_tp3d(&object->rot, &co->rot);
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
	if (!object->set)
		cone_normal(ray, object, object->rot);
	return (calc_delta(a, b, c));
}

static	void		cylinder_normal(t_ray *ray, t_object *object, t_p3d rot)
{
	t_cylinder	*cyl;
	double		m;

	cyl = (t_cylinder *)object->ptr;

	object->inter = sum_tp3d(ray->pos, mult_nb_tp3d(ray->dir, object->t));
	// rot = rotate_tp3d(&object->rot, &cyl->rot);
	m = dot_product_tp3d(ray->dir, mult_nb_tp3d(rot, object->t)) +
	dot_product_tp3d(object->offset, rot);

	object->normal = sub_tp3d(sub_tp3d(object->inter, cyl->pos),
	mult_nb_tp3d(rot, m));
	normalized(&object->normal);
}

double				calc_cylinder(t_object *object, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;
	t_p3d		rot;

	cyl = (t_cylinder *)object->ptr;
	object->offset = sub_tp3d(ray->pos, cyl->pos);
	rot = rotate_tp3d(&object->rot, &cyl->rot);

	a = dot_product_tp3d(ray->dir, ray->dir) -
	dot_product_tp3d(ray->dir, rot) *
	dot_product_tp3d(ray->dir, rot);
	b = 2.0f * (dot_product_tp3d(ray->dir, object->offset) -
	dot_product_tp3d(ray->dir, rot) *
	dot_product_tp3d(object->offset, rot));
	c = dot_product_tp3d(object->offset, object->offset) -
	dot_product_tp3d(object->offset, rot) *
	dot_product_tp3d(object->offset, rot) -
	cyl->radius * cyl->radius;
	object->t = calc_delta(a, b, c);
	if (!object->set)
		cylinder_normal(ray, object, rot);
	return (object->t);
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
	b = 2.0f * dot_product_tp3d(ray->dir, object->offset);
	c = dot_product_tp3d(object->offset, object->offset) - s->radius *
	s->radius;
	return (calc_delta(a, b, c));
}
