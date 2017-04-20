/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:52:41 by lgatibel          #+#    #+#             */
/*   Updated: 2017/01/25 11:49:50 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <libft.h>
# include <math.h>
# include <error.h>
# include <fcntl.h>
# include <tp3d.h>
# include <stdio.h>// a virer

# define WIDTH 1244.0f
# define HEIGHT 588.0f
# define RED 0XFF0000
# define GREEN 0X00FF00
# define BLUE 0X0000FF
# define WHITE 0XFFFFFF
# define BLACK 0x000000
# define YELLOW 0XF7FA04
# define PURPLE 0X8D44D6
# define CUSTOM 0x0ECB25
# define FONT 0x0
# define COEFF 1
# define ERROR 0
# define OK 1

# define PLANE 1
# define SPHERE 2
# define CONE 3
# define CYLINDER 4

typedef enum		e_bool
{
	undefined = -1,
	false,
	true
}					t_bool;

typedef struct		s_sphere
{
	t_p3d		pos;
	t_p3d		rot;
	double		radius;
}					t_sphere;

typedef struct		s_cone
{
	t_p3d		pos;
	t_p3d		rot;
	double		radius;
}					t_cone;

typedef struct		s_cylinder
{
	t_p3d		pos;
	t_p3d		rot;
	double		radius;
}					t_cylinder;

typedef struct		s_plane
{
	t_p3d		pos;
	t_p3d		normal;
	double		d;
}					t_plane;

typedef struct		s_ray
{
	t_p3d			pos;
	t_p3d			dir;
	int				is_light;
}					t_ray;

typedef struct		s_object
{
	char				type;
	void				*ptr;
	struct s_object		*next;
	int					color;
	double				dist;
	t_p3d				normal;
	t_p3d				offset;
	t_p3d				rot;
	t_p3d				inter;
	t_bool				set;
	// double				norminter;
	// double				normlight;
	double				t;
}					t_object;

typedef struct		s_cam
{
	t_p3d		pos;
	t_p3d		rot;
	double		focal;
}					t_cam;

typedef struct		s_env
{
	t_cam		cam;
	t_ray		ray;
	t_ray		light;
	t_object	*object;
	t_object	*nearest_object;

	t_p3d		indent;
	t_p3d		basis;
	double		length;

	int			font_color;
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_addr;
	int			bpp;
	int			size_line;
	int			endian;

	char		*line;
	int			i;
}					t_env;

t_object			*parse_file(char *file, t_env *env);

void				set_env(t_env *env);
void				set_ray(t_ray *ray, t_env *env);
int					set_vecteur(char **tab, t_p3d *point);
int					set_rotation_vecteur(char **tab, t_p3d *point);
int					set_radius(char **tab, double *radius);
int					set_color(char **tab, int *color);
void				set_object(t_env *env, int fd, t_object **object);
void				set_cam(t_cam *cam, int fd);
void				set_spot(t_ray *ray, int fd);
void				manage_parameter(int fd, t_env *env);

int					calc_light(t_env *env);
double				calc_sphere(t_object *object, t_ray *ray);
double				calc_cone(t_object *object, t_ray *ray);
double				calc_cylinder(t_object *object, t_ray *ray);
double				calc_plane(t_object *object, t_ray *ray);
double				calc_norm(t_p3d *vec);
double				length_ray(t_ray *ray, double t, t_object *object);
void				calc_ray(t_env *env, double x, double y);

t_p3d				calc_sphere_normal(t_p3d *intersect, t_object *object);
t_p3d				calc_cylinder_normal(t_p3d *intersect, t_object *object);
t_p3d				calc_cone_normal(t_object *object);
t_p3d				calc_plane_normal(t_object *object);
t_p3d				calc_normal(t_p3d *intersect, t_object *object);

t_object			*calc_object(t_object *object, t_ray *ray);

void				reset_object(t_object *object);
void				normalized(t_p3d *point);
void				event(t_env *env);
void				refresh(t_env *env);
double				color(int object_color, int rgb);
int					args_required(char *ok, int nb);

int					blink(t_env *env);
void				print_line(char **str);
void				malloc_object(t_object **obj, t_object **object, int i);

void				set_offset(t_object *object, t_ray *ray);


t_p3d			rotate_tp(t_p3d *ray, t_p3d rot, t_p3d pos);

#endif
