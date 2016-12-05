/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:54:12 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/29 11:57:30 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TP3D_H
# define TP3D_H
# include <libft.h>

typedef struct		s_p3d
{
	double		x;
	double		y;
	double		z;
}					t_p3d;

t_p3d				square_tp3d(t_p3d *src);
t_p3d				sum_tp3d(t_p3d vector1, t_p3d vector2);
t_p3d				mult_nb_tp3d(t_p3d vector, double nb);
t_p3d				sub_tp3d(t_p3d vector1, t_p3d vector2);
double				mult_tp3d(t_p3d vector1, t_p3d vector2);
double				div_tp3d(t_p3d vector1, t_p3d vector2);
void				cpy_tp3d(t_p3d *dest, t_p3d src);

void				print_tp3d(t_p3d *vector);
void				set_tp3d(t_p3d *vec, double x, double y,
double z);
#endif