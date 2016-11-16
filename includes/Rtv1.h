/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:52:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/16 16:22:07 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <libft.h>
# include <math.h>
# include <error.h>

// a virer
# include <stdio.h>
# define XO 0
# define YO 0
# define ZO -10
//
# define WIDTH 600
# define HEIGHT 600
# define RAYON_SIZE 1000
# define RED 0XFF0000
# define GREEN 0X00FF00
# define BLUE 0X0000FF
# define WHITE 0XFFFFFF
# define CUSTOM 0x0ECB25
# define ANGLE 90
# define SQUARE 1
# define RECTANGLE 2
# define TRIANGLE 3
# define SPHERE 4
# define CONE 5
# define CYLINDER 6
# define T 600

typedef enum		e_bool
{
	undefined = -1,
	false,
	true
}					t_bool;

typedef struct		s_point
{
	double		x;
	double		y;
	double		z;
}					t_point;

typedef struct		s_square
{
	t_point		pos;
	t_point		rot;
	int			width;
}					t_square;

typedef struct		s_rectangle
{
	t_point		pos;
	t_point		rot;
	int			length;
	int			width;
}					t_rectangle;

typedef struct		s_triangle
{
	t_point		pos;
	t_point		rot;
	int			height;
	int			base;
}					t_triangle;

typedef struct		s_sphere
{
	double		x;
	double		y;
	double		z;
	int			radius;
}					t_sphere;

typedef struct		s_cone
{
	t_point		pos;
	int			height;
	int			base;
	int			radius;
}					t_cone;

typedef struct		s_cylinder
{
	t_point		pos;
	int			height;
	int			base;
	int			radius;
}					t_cylinder;

typedef struct		s_ray
{
	t_point		pos;
	t_point		dir;
	t_point		org;
}					t_ray;

typedef struct		s_object
{
	char			type;
	void			*ptr;
	struct s_object	*next;
}					t_object;

typedef struct		s_viewplane
{
	double		width;
	double		height;
	double		dist;
	t_point		vecdir;
	t_point		upvec;
	t_point		rvec;
	t_point		upleft;
	
}					t_viewplane;

typedef struct		s_env
{
	t_point		cam;
	t_viewplane viewplane;
	t_ray		ray;
	t_object	*object;
	void		*mlx;
	void		*win;
	void		*img;
	double		xindent;
	double		yindent;
	int			*img_addr;
	int			bpp;
	int			size_line;
	int			endian;
	double		t;
}					t_env;

t_env				*set_env(t_env *env);

void				set_ray(t_ray *ray);

void				set_sphere(t_object **object);

double				calc_delta(t_env *env, double *t0, double *t1);
void				calc_ray(t_env *env, double x, double y);
t_bool				calc_sphere(t_object *object, t_ray ray, double *t);


t_point				matrice_sum_1x1(t_point matrice1, t_point matrice2);
t_point				matrice_mult_1x1_nb(t_point matrice, double nb);
t_point				matrice_sub_1x1(t_point matrice1, t_point matrice2);
double				matrice_mult_1x1(t_point matrice1, t_point matrice2);
void				matrice_cpy(t_point *dest, t_point src);

void				normalized(t_point *point);
//void				trace(t_object *object, t_env env);
int					color(int color, double t);
int					ft_exit(int keycode);
#endif
