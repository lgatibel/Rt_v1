/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 13:19:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/02 14:54:18 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rtv1.h>
#include <unistd.h>
#include <libft.h>
#include <math.h>
#include <stdio.h>


void				set_segment(t_segment *segment)
{
	segment->posx = 100;
	segment->posy = 80;
	segment->y = 80;
	segment->x = 350;
	if (segment->y != segment->posy)
	segment->pente = (segment->x - segment->posx) / (segment->y - segment->posy);
	else
	segment->pente = 0;
}

static void				trace_segment(t_mlx *ptr, t_segment segment)
{
	double	xs;
	double	ys;
	double	xe;
	double	ye;
	char	*img;

	xs = segment.posx;
	ys = segment.posy;
	xe = segment.x;
	ye = segment.y;
	img = ptr->img_addr + ((int)ys * ptr->size_line);
	while (ys <= WIDTH && ys <= ye)
	{
		xs = segment.posx;
		while (xs <= WIDTH && xs <= xe)
		{
			if (ye != ys && ((xs - segment.posx) / (ys - segment.posy)) == segment.pente)
				img[((int)xs) * 4 + GREEN] = 255;
			else if (ye == ys && segment.pente == 0)
				img[((int)xs) * 4 + RED] = 255;
			xs++;
		}
		img += ptr->size_line;
		ys++;
	}
}

void				set_rectangle(t_rectangle *rectangle)
{
	rectangle->posx = 100;
	rectangle->posy = 100;
	rectangle->length = 50;
	rectangle->width = 100;
}

static void				trace_rectangle(t_mlx *ptr, t_rectangle rectangle)
{
	double	xs;
	double	ys;
	double	xe;
	double	ye;
	char	*img;

	xs = rectangle.posx;
	ys = rectangle.posy;
	xe = xs + rectangle.width;
	ye = ys + rectangle.length;
	img = ptr->img_addr + ((int)ys * ptr->size_line);
	while (ys <= WIDTH && ys <= ye)
	{
		xs = rectangle.posx;
		while (xs <= WIDTH && xs <= xe)
		{
			img[((int)xs) * 4 + BLUE] = 255;
			xs++;
		}
		img += ptr->size_line;
		ys++;
	}
}
void				set_square(t_square *square)
{
	square->width = 50;
	square->posx = 300;
	square->posy = 100;
}

static void				trace_square(t_mlx *ptr, t_square square)
{
	double	xs;
	double	ys;
	double	xe;
	double	ye;
	char	*img;

	xs = square.posx;
	ys = square.posy;
	xe = xs + square.width;
	ye = ys + square.width;
	img = ptr->img_addr + ((int)ys * ptr->size_line);
	while (ys <= WIDTH && ys <= ye)
	{
		xs = square.posx;
		while (xs <= WIDTH && xs <= xe)
		{
			img[((int)xs) * 4 + BLUE] = 255;
			xs++;
		}
		img += ptr->size_line;
		ys++;
	}
}
int					main(void)
{
	t_mlx		ptr;
	t_segment	segment;
	t_square	square;
	t_rectangle	rectangle;

	ptr.bpp = 0;
	ptr.size_line = 0;
	ptr.endian = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "hello");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.img_addr = mlx_get_data_addr(ptr.img, &ptr.bpp, &ptr.size_line, &ptr.endian);
	set_segment(&segment);
	set_square(&square);
	set_rectangle(&rectangle);
	trace_segment(&ptr, segment);
	trace_square(&ptr, square);
	trace_rectangle(&ptr, rectangle);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	write(1, "finish", 6);
	mlx_loop(ptr.mlx);
	return (0);
}
