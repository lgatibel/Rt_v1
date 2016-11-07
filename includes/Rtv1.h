/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:52:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/07 18:19:29 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
#include <mlx.h>
# define WIDTH 640
# define HEIGHT 480
# define BLUE 0XFF0000
# define GREEN 0X00FF00
# define RED 0X0000FF
# define WHITE 0XFFFFFF
# define CUSTOM 0X66FF33
# define ANGLE 90

#define		SQUARE 1
#define		RECTANGLE 2
#define		TRIANGLE 3
#define		SPHERE 4
#define		CONE 5
#define		CYLINDER 6

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

typedef struct	s_sphere
{
	t_point		pos;
	int			radius;
}				t_sphere;

typedef struct	s_cone
{
	t_point		pos;
	int			height;
	int			base;
	int			radius;
}				t_cone;

typedef struct	s_cylinder
{
	t_point		pos;
	int			height;
	int			base;
	int			radius;
}				t_cylinder;






typedef struct	s_ray
{
	double		x;
	double		y;
	double		z;
	double		dirx;
	double		diry;
	double		dirz;
}				t_ray;



typedef struct			s_object
{
	char				type;
	void				*ptr;
	struct s_object		*next;
}						t_object;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	t_object		object;
	t_ray			ray;
}					t_env;
#endif
