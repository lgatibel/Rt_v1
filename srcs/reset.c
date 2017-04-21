/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:02:26 by lgatibel          #+#    #+#             */
/*   Updated: 2017/04/13 13:02:27 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void				reset_object(t_object *object)
{
	while (object)
	{

		object->set = false;
		set_tp3d(&object->rot, 0.0f, 1.0f, 0.0f);
		object = object->next;
	}
}
