/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:36:51 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 11:42:06 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				trace(t_object *object, t_env env)
{
	t_ray		ray;
	int			i;
	int			j;
	double		t;

	i = -1;
	j = -1;
	t = 1000;
	ray = env.ray;
	normalized(&ray.dir);
	while (++j < HEIGHT)
	{
		i = -1;
		ray.pos.y = j;
		ray.pos.x = i;
		while (++i < WIDTH)
		{
			if (calc_sphere(object, ray, &t))
			{
				*(env.img_addr + i + (env.size_line * j) / 4) = BLUE  - BLUE / t;
			printf("t = %f\n",t);
			t = 1000;
			}
			ray.pos.x = i;
		}
	}
}
