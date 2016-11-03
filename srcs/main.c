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

void				set_segment(t_segment *segment)
{
	segment->x1 = 500;
	segment->y1 = 500;
	segment->x2 = 750;
	segment->y2 = 500;
	if (segment->y2 != segment->y1)
	segment->pente = (segment->x2 - segment->x1) / (segment->y2 - segment->y1);
	else
	segment->pente = 0;
}

void				trace(t_mlx *ptr, t_segment segment)
{
	double	xs;
	double	ys;
	double	xe;
	double	ye;
	char	*img;

	xs = segment.x1;
	ys = segment.y1;
	xe = segment.x1;
	ye = segment.y1;
	img = ptr->img_addr + ((int)ys * ptr->size_line);
	while (ye <= WIDTH && ye <= ys)
	{
		xe = segment.x1;
		while (xe <= WIDTH && xe <= xs)
		{
			if (ye != ys && ((xe - xs) /(ye - ys)) == segment.pente)
				img[( (int)xe) + 1] = 255;
			else //if (ye == ys && segment.pente == 0)
				img[( (int)xe) + 0] = 255;
			xe++;
		write(1, "ok\n",3);
		}
		img += ptr->size_line;
		ye++;
	}
}

int					main(void)
{
	t_mlx		ptr;
	t_segment	segment;

	ptr.bpp = 0;
	ptr.size_line = 0;
	ptr.endian = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "hello");
	ptr.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	ptr.img_addr = mlx_get_data_addr(ptr.img, &ptr.bpp, &ptr.size_line, &ptr.endian);
	set_segment(&segment);
	trace(&ptr, segment);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	write(1, "finish", 6);
	mlx_loop(ptr.mlx);
	return (0);
}
