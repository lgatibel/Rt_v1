TARGET = rt_v1

SCR_NAME = main.c

SCR_PATH = ./srcs/

#include <mlx.h>
OBJ_NAME = 

SRCS = ()

OBJ_PATH = ../objs/


all: $(TARGET)

$(TARGET):



clean:
@rm -rf $(OBJ_PATH)

fclean: clean
@rm $(TARGET)

re: fclean all
