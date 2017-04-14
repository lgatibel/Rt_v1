/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:44:09 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/17 17:49:23 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *erase;

	erase = *alst;
	while (erase)
	{
		del(erase->content, erase->content_size);
		erase = erase->next;
		if (erase)
		{
			free(*alst);
			*alst = erase;
		}
	}
	ft_memdel((void **)alst);
}
