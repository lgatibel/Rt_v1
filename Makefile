TARGET = rt_v1

#Sources
SRC_NAME = main.c set_object.c sphere.c exit.c
SRC_PATH = ./srcs/
SRCS = $(addprefix $(SRC_PATH),$(SRC_NAME))
###############

#Objects
OBJ_PATH = ./objs/
OBJ = $(addprefix $(OBJ_PATH),$(SRC_NAME:.c=.o))
LIBFT_PATH = ./Libft/
LIBMLX_PATH = ./minilibx/minilibx_macos/
##############

#Includes
INC_RT = -I./includes/
INC_LIBFT = -I./Libft/includes/
INC_LIBMLX = -I./minilibx/minilibx_macos/
##############

#Librarys
LIBFT = -L./Libft/ -lft
LIBMLX = -L./minilibx/minilibx_macos/ -lmlx
#############

#Frameworks
APPKIT = -framework Appkit
OPENGL = -framework Opengl
############

#Flags
CFLAGS = -Wall -Wextra -Werror -Weverything
CC = gcc

DEBUGFLAG1 = -g3
DEBUGFLAG2 = -fsanitize=address
#############


all: libft libmlx $(TARGET)

.PHONY: libmlx libft clean fclean re obj

libft:
	@echo "######## 1/3 Libft ########"
	@make -C $(LIBFT_PATH)
	@echo "\n########################"

libmlx:
	@echo "\n##### 2/3 libmlx #########"
	@make -C $(LIBMLX_PATH)
	@echo "\n########################"

$(TARGET): $(OBJ)
	@echo "\n######## 3/3 Rt_v1 ########"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(APPKIT) $(OPENGL) -o $(TARGET)
	@echo "\n########################"

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(SRC_PATH),%.c)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@$(CC) $(CFLAGS) -c $< $(INC_RT) $(INC_LIBFT) $(INC_LIBMLX) -o $@


clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(TARGET)

re: fclean all
