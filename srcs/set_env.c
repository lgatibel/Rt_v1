/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:25:38 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 16:19:21 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void			set_tp3d(t_p3d *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

static void			set_mlx(t_env **tmp)
{
	(*tmp)->mlx = mlx_init();
	(*tmp)->win = mlx_new_window((*tmp)->mlx, WIDTH, HEIGHT, "hello");
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

	if (!(tmp = (t_env *)malloc(sizeof(t_env))))
		error(INIT, __LINE__ - 1, __FILE__, EXIT);
	view = &tmp->viewplane;
	tmp->color = BLACK;
	tmp->viewplane.width = 0.5;
	tmp->viewplane.height = 0.5;
	tmp->viewplane.dist = 1;
	set_tp3d(&tmp->viewplane.vecdir, 0, 0, 1);
	set_tp3d(&tmp->viewplane.upvec, 0, 1, 0);
	set_tp3d(&tmp->viewplane.rvec, 1, 0, 0);
	set_tp3d(&tmp->cam, 0, 0, 1);
	view->upleft = tp3d_sub(
	tp3d_sum(
	tp3d_sum(tmp->cam,
	tp3d_mult_nb(view->vecdir, view->dist)),
	tp3d_mult_nb(view->upvec, view->height / 2.0f)),
	tp3d_mult_nb(view->rvec, view->width / 2.0f));
	tmp->xindent = (float)tmp->viewplane.width / (float)WIDTH;
	tmp->yindent = (float)tmp->viewplane.height / (float)HEIGHT;
	tmp->t = -1;
	set_mlx(&tmp);
	*env = tmp;
	printf("x = %f, y = %f, z = %f\n",view->upleft.x,view->upleft.y,view->upleft.z);
}
