/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:43:07 by lgatibel          #+#    #+#             */
/*   Updated: 2016/12/05 10:07:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFF_SIZE 32

typedef struct	s_cache
{
	char			str[BUFF_SIZE + 1];
	int				fd;
	int				fill;
	int				c;
	void			*next;
}				t_cache;

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_itoa(int n);
char			*ft_lltoa_base(long long nbr, int base);
char			*ft_ulltoa_base(unsigned long long nbr, int base);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_reverse_tab(char *tab, int start, int end);
char			*ft_strndupchr(const char c, int size);
char			*ft_strtrim(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
double			ft_absolute(double nb);
double			ft_atod(const char *str);
double			ft_square_root(double nb);
int				ft_power(int nb, int power);

int				ft_ishexa(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strisnum(char *str);
int				ft_strishexa(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_str_is_double(char *str);
int				ft_str_is_hexa(const char *str);

int				ft_toupper(int c);
int				ft_tolower(int c);

int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);

int				ft_is_space(const char c);

int				ft_strichr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				get_next_line(int const fd, char **line);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *s1, const char *s2, size_t n);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_strclr(char *s);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_putnstr(char const *s, int n);
void			ft_putsntr_fd(char *s, int fd, int n);
int				ft_lstcount(t_list *list);
char			*ft_strtolower(char *s);
char			*ft_strtoupper(char *s);
#endif
