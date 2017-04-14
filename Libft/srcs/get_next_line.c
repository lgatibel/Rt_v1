/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:11:30 by lgatibel          #+#    #+#             */
/*   Updated: 2016/11/17 12:51:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_cache		*ft_set_cache(t_cache **cache, int fd)
{
	if ((*cache)->fd == fd)
	{
		if ((*cache)->str[0] == '\0')
			(*cache)->fill = 0;
		(*cache)->c = 0;
		return (*cache);
	}
	else
	{
		(*cache)->next = (t_cache *)malloc(sizeof(t_cache));
		*cache = (*cache)->next;
		(*cache)->fd = fd;
		(*cache)->fill = 0;
		(*cache)->c = 0;
		(*cache)->next = NULL;
		ft_bzero((*cache)->str, BUFF_SIZE);
	}
	return (*cache);
}

static int			ft_fill_line(char **line, char *buff)
{
	char	*svg;

	svg = *line;
	if (!svg)
		*line = ft_strdup(buff);
	else if (svg)
		*line = ft_strjoin(svg, buff);
	ft_strdel(&svg);
	return (0);
}

static int			ft_fill_cache(char *buff, t_cache **cache, char **line,
		int option)
{
	char	svg[BUFF_SIZE];
	int		c;

	if (option == 0)
	{
		ft_strcpy((*cache)->str, &buff[1]);
		(*cache)->fill = 1;
		ft_strclr(buff);
		return (0);
	}
	if ((c = ft_strichr((*cache)->str, '\n')) != -1)
	{
		ft_strncpy(svg, (*cache)->str, c);
		svg[c] = '\0';
		ft_memmove((*cache)->str, &(*cache)->str[c + 1], BUFF_SIZE);
		*line = ft_strdup(svg);
		return (1);
	}
	else
	{
		*line = ft_strdup((*cache)->str);
		ft_bzero((*cache)->str, BUFF_SIZE);
	}
	return (0);
}

static int			ft_read(int const fd, char **line, t_cache **cache)
{
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	int			c;

	c = -1;
	ft_set_cache(cache, fd);
	ft_bzero(buff, BUFF_SIZE);
	if ((*cache)->fill)
		(*cache)->c = ft_fill_cache(*line, cache, line, 1);
	while (!(*cache)->c && c == -1 && (bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		c = ft_strichr(buff, '\n');
		if (c != -1)
			ft_fill_cache(&buff[c], cache, line, 0);
		ft_fill_line(line, &buff[0]);
	}
	if (fd < 0 || bytes == -1)
		return (-1);
	if (bytes == 0 && (*cache)->fill == 0 && (*cache)->c == 0 && !*line)
		return (0);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_cache	cache;
	t_cache			**tmp;
	t_cache			*svg;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	svg = &cache;
	if (svg->fd == fd)
		tmp = &svg;
	else
	{
		while (svg->next && svg->fd != fd)
			svg = svg->next;
		tmp = &svg;
	}
	return (ft_read(fd, line, tmp));
}
