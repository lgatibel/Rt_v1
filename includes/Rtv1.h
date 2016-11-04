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
# define WIDTH 500
# define HEIGHT 500
# define BLUE 0
# define GREEN 1
# define RED 2

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
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		pente;
}					t_segment;
#endif
