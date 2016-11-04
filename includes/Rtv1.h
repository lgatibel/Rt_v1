/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:52:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/02 14:53:43 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
#include <mlx.h>
# define WIDTH 1200
# define HEIGHT 800
# define BLUE 0
# define GREEN 1
# define RED 2
# define ANGLE 90

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_segment
{
	int		posx;
	int		posy;
	int		posz;
	int		x;
	int		y;
	int		pente;
}					t_segment;

typedef struct		s_square
{
	int		posx;
	int		posy;
	int		posz;
	int		width;
}					t_square;

typedef struct		s_rectangle
{
	int		posx;
	int		posy;
	int		posz;
	int		length;
	int		width;
}					t_rectangle;
#endif
