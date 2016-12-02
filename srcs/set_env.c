/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:25:38 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/01 17:28:26 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			set_tp3d(t_p3d *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

static void			set_mlx(t_env **tmp)
{
	(*tmp)->mlx = mlx_init();
	(*tmp)->win = mlx_new_window((*tmp)->mlx, WIDTH, HEIGHT,
			"hello");
	(*tmp)->img = mlx_new_image((*tmp)->mlx, WIDTH, HEIGHT);
	(*tmp)->bpp = 0;
	(*tmp)->size_line = 0;
	(*tmp)->endian = 0;
	(*tmp)->img_addr = (int *)mlx_get_data_addr((*tmp)->img,
	&(*tmp)->bpp, &(*tmp)->size_line, &(*tmp)->endian);
}

void				set_env(t_env **env)
{
	t_env			*tmp;
	t_viewplane		*view;

	tmp = *env;
	view = &tmp->viewplane;
	tmp->color = BLACK;
	tmp->viewplane.width = VIEW_WIDTH;
	tmp->viewplane.height = VIEW_HEIGHT;
	tmp->viewplane.dist = 1;
	//voir pour une converison humaine des point de rotation et position
//	set_tp3d(&tmp->intersect, 0, 0, 0);
//	set_tp3d(&tmp->cam.pos, 3, 4, 5);
//	set_tp3d(&tmp->cam.rot, 0, 0, 1);
	set_tp3d(&view->upvec, 0, 1, 0);
	set_tp3d(&view->rvec, 1, 0, 0);
	view->upleft = sub_tp3d(
	sum_tp3d(
	sum_tp3d(tmp->cam.pos, mult_nb_tp3d(tmp->cam.rot,
	view->dist)), mult_nb_tp3d(view->upvec, view->height /
	2.0f)), mult_nb_tp3d(view->rvec, view->width / 2.0f));
	tmp->xindent = tmp->viewplane.width / WIDTH;
	tmp->yindent = tmp->viewplane.height / HEIGHT;
	tmp->t = -1;
	tmp->i = 0;
	set_mlx(&tmp);
//	*env = tmp;
}
