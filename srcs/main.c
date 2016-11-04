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

void				set_segment(t_segment *segment)
{
	segment->x1 = 250;
	segment->y1 = 250;
	segment->y2 = 400;
	segment->x2 = 250;
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
	xe = xs;
	ye = ys;
	img = ptr->img_addr + ((int)ys * ptr->size_line);
	while (ye <= WIDTH && ye <= segment.y2)
	{
		xe = xs;
		while (xe <= WIDTH && xe <= segment.x2)
		{
			if (ye != ys && ((xe - xs) / (ye - ys)) == segment.pente)
				img[((int)xe) * 4 + GREEN] = 255;
			else if (ye == ys && segment.pente == 0)
				img[((int)xe) * 4 + RED] = 255;
			xe++;
	ft_putchar('\n');
	ft_putnbr(xe);
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
