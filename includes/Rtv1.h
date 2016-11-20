/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:52:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 15:40:22 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <libft.h>
# include <math.h>
# include <error.h>
# include <fcntl.h>

// a virer
# include <stdio.h>
//
# define WIDTH 600
# define HEIGHT 600
# define RAYON_SIZE 1000

# define RED 0XFF0000
# define GREEN 0X00FF00
# define BLUE 0X0000FF
# define WHITE 0XFFFFFF
# define BLACK 0x000000
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

typedef struct		s_p3d
{
	double		x;
	double		y;
	double		z;
}					t_p3d;

typedef struct		s_square
{
	t_p3d		pos;
	t_p3d		rot;
	int			width;
}					t_square;

typedef struct		s_rectangle
{
	t_p3d		pos;
	t_p3d		rot;
	int			length;
	int			width;
}					t_rectangle;

typedef struct		s_triangle
{
	t_p3d		pos;
	t_p3d		rot;
	int			height;
	int			base;
}					t_triangle;

typedef struct		s_sphere
{
	t_p3d		pos;
	t_p3d		rot;
	double		x;
	double		y;
	double		z;
	int			radius;
}					t_sphere;

typedef struct		s_cone
{
	t_p3d		pos;
	t_p3d		rot;
	double		x;
	double		y;
	double		z;
	int			height;
	int			radius;
}					t_cone;

typedef struct		s_cylinder
{
	t_p3d		pos;
	t_p3d		rot;
	double		x;
	double		y;
	double		z;
	int			height;
	int			base;
	int			radius;
}					t_cylinder;

typedef struct		s_ray
{
	t_p3d		pos;
	t_p3d		dir;
}					t_ray;

typedef struct		s_object
{
	char				type;
	void				*ptr;
	struct s_object		*next;
	int					color;
}					t_object;

typedef struct		s_viewplane
{
	double		width;
	double		height;
	double		dist;
	t_p3d		vecdir;
	t_p3d		upvec;
	t_p3d		rvec;
	t_p3d		upleft;

}					t_viewplane;

typedef struct		s_env
{
	t_p3d		cam;
	t_object	*object;
	t_viewplane viewplane;
	t_ray		ray;

	double		xindent;
	double		yindent;
	int			color;

	void		*mlx;
	void		*win;
	void		*img;
	int			*img_addr;
	int			bpp;
	int			size_line;
	int			endian;

	double		t;
}					t_env;

typedef struct		s_grtv1
{
	t_env		*env;
	t_object	*object;
	t_ray		*ray;
}					t_grtv1;

void				parse_file(char *file, t_env **env, t_object **object);

void				set_env(t_env **env);
void				set_ray(t_ray *ray);
//void				set_sphere(t_object **object);
//void				set_cylinder(t_object **object);
void				set_object(t_object **object);

double				calc_sphere(t_object *object, double *t0, double *t1,
t_env **env);
double				calc_cylinder(t_object *object, double *t0, double *t1,
t_env **env);
void				calc_ray(t_env *env, double x, double y);
//t_bool				calc_sphere(t_object *object, t_ray ray, double *t);


t_p3d				tp3d_sum(t_p3d matrice1, t_p3d matrice2);
t_p3d				tp3d_mult_nb(t_p3d matrice, double nb);
t_p3d				tp3d_sub(t_p3d matrice1, t_p3d matrice2);
double				tp3d_mult(t_p3d matrice1, t_p3d matrice2);
void				tp3d_cpy(t_p3d *dest, t_p3d src);

void				normalized(t_p3d *point);
//void				trace(t_object *object, t_env env);
void				event(t_env *env);
int					color(int color, double t);
#endif
