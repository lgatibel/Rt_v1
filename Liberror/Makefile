# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 18:07:02 by lgatibel          #+#    #+#              #
#    Updated: 2016/11/10 18:14:40 by lgatibel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = liberror.a

SRC_NAME = error.c
SRC_PATH = ./srcs/
SRCS = $(addprefix)

OBJ_NAME = $(SRC_NAME:(.c=.o))
OBJ_PATH = ./objs/
OBJS = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:

$(TARGET): $(OBJ)

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(OBJ_SRC),%.c)
	@mkdir -p $(OBJ_PATH) 2>dev>null
	$(CC) $(CFLAGS) -c 

clean:

fclean: clean

re: fclean re:

