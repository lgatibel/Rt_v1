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
	segment->y2 = 750;
	segment->pente = (segment->x2 - segment->x1) / (segment->y2 - segment->y1);
}

void				trace(t_mlx *ptr, t_segment segment)
{
	int		i;
	int		j;
	char	*img;

	img = ptr->img_addr;
	j = segment.y1;
	while (j && j <= WIDTH && j <= segment.y2)
	{
		i = segment.x1;
		while (i && i <= WIDTH && i <= segment.x2)
		{
			if (j != segment.y1 && ((i - segment.x1) /(j - segment.y1)) == segment.pente)
				img[(ptr->bpp * i) + 1] = 255;
			i++;
		}
		img += ptr->size_line;
		j++;
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
