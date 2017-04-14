# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 09:23:55 by lgatibel          #+#    #+#              #
#    Updated: 2016/12/16 11:32:36 by lgatibel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c  ft_strcat.c ft_strchr.c ft_strclr.c \
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c  \
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c \
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_putnstr.c ft_putnstr_fd.c ft_lstcount.c ft_strichr.c get_next_line.c \
ft_power.c ft_square_root.c ft_absolute.c ft_strndupchr.c ft_atod.c ft_atoi_base.c ft_ishexa.c ft_is_space.c ft_str_is_double.c ft_str_is_hexa.c ft_lltoa_base.c ft_strtoupper.c ft_reverse_tab.c \
ft_ulltoa_base.c error.c ft_strisnum.c ft_strishexa.c

OBJ_PATH = ./objs/

SRC_PATH = ./srcs/

OBJ = $(addprefix $(OBJ_PATH),$(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

CFLAGS = -Wall -Wextra -Werror

LIB = -L. -lft

INC = -I./includes/

INC_PATH = ./includes/

CC = clang

all: $(NAME)

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Create :\n$(NAME)\ndone1!\n"

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(SRC_PATH),%.c)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	@norminette $(SRC_PATH) $(INC_PATH)
