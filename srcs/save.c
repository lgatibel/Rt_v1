/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:58:55 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/06 16:58:56 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   size_t			twocolor_lerp(unsigned int a, unsigned int b, const float pc)
   {
   t_pos	color;

   if (pc <= 0.0f)
   return (a);
   if (pc >=	 1.0f)
   return (b);
   color.x = (float)(a & 0xff0000) * (1.0f - pc) + (float)(b & 0xff0000) * pc;
   color.y = (float)(a & 0x00ff00) * (1.0f - pc) + (float)(b & 0x00ff00) * pc;
   color.z = (float)(a & 0x0000ff) * (1.0f - pc) + (float)(b & 0x0000ff) * pc;
   return((((unsigned int)color.x) & 0xff0000) |
   (((unsigned int)color.y) & 0x00ff00) |
   (((unsigned int)color.z) & 0x0000ff));
   }
   *//*
		size_t			onecolor_lerp(unsigned int a, const float pc)
		{
		int		b;
		int		x;
		int		y;
		int		z;

		b = (a >> 1) & 8355711;
		if (pc <= 0.0f)
		return (a);
		if (pc >= 1.0f)
		return (b);
		x = (float)(a & 0xff0000) * (1.0f - pc) + (float)(b & 0xff0000) * pc;
		y = (float)(a & 0x00ff00) * (1.0f - pc) + (float)(b & 0x00ff00) * pc;
		z = (float)(a & 0x0000ff) * (1.0f - pc) + (float)(b & 0x0000ff) * pc;
		return((((unsigned int)x) & 0xff0000) |
		(((unsigned int)y) & 0x00ff00) |
		(((unsigned int)z) & 0x0000ff));
		}*/
// a couleur
// pc pourcentage degrader t / (posz_objs - radius)
