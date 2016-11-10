/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:36:51 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/10 12:52:43 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				trace(t_object *object, t_env env)
{
	t_ray		ray;

	ray = env.ray;
	normalized(&ray.dir);
	while (ray.pos.y < HEIGHT)
	{
		ray.pos.x = 0;
		while (ray.pos.x < WIDTH)
		{
			if (calc_sphere(object, ray, &env.t))
			{
				*(env.img_addr + (int)ray.pos.x + (env.size_line * (int)ray.pos.y) / 4) = WHITE  / env.t;
				printf("t = %f\n",env.t);
				env.t = 1000;
			}
			ray.pos.x++;
		}
		ray.pos.y++;
	}
}
