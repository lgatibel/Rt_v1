vpath

TARGET = rtv1
#Sources
SRC_NAME = main.c set_object.c print_tp3d.c calc_tp3d.c calc_tp3d_annexe.c \
ray.c color.c parse.c set_env.c calc.c event.c tools.c set_tp3d.c set.c \
calc_normal.c
SRC_PATH = ./srcs/
SRCS = $(addprefix $(SRC_PATH),$(SRC_NAME))
###############

#Objects
OBJ_PATH = ./objs/
OBJ = $(addprefix $(OBJ_PATH),$(SRC_NAME:.c=.o))
LIBFT_PATH = ./Libft/
LIBMLX_PATH = ./minilibx/
##############

#Includes
INC_RT = -I./includes/
INC_LIBFT = -I./Libft/includes/
INC_LIBMLX = -I./minilibx/
##############

#Librarys
LIBFT = -L./Libft/ -lft
LIBFT_NAME = ./Libft/libft.a
LIBMLX = -L./minilibx/ -lmlx
#############

#Frameworks
APPKIT = -framework Appkit
OPENGL = -framework Opengl
############

#Flags
CFLAGS = -Wall -Wextra -Werror 
CC = gcc

DFLAG1 = -fsanitize=address
DFLAG2 = -g3
#############

all: $(TARGET)

.PHONY: all clean fclean re

$(TARGET): $(OBJ)
	@echo "\x1b[32m\n######## 1/3 libft ########\x1b[0m"
	@make -C $(LIBFT_PATH)
	@echo "\x1b[32m\n########################\x1b[0m"
	@echo "\x1b[32m\n######## 2/3 libmlx ########\x1b[0m"
	@make -C $(LIBMLX_PATH)
	@echo "\x1b[32m\n########################\x1b[0m"
	@echo "\x1b[32m\n######## 3/3 Rt_v1 ########\x1b[0m"
	#$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(APPKIT) $(OPENGL) -o $(TARGET)
#	$(CC) $(CFLAGS) $(DFLAG1) $(OBJ) $(LIBFT) $(LIBMLX) $(APPKIT) $(OPENGL) -o $(TARGET) $(DFLAG2)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(APPKIT) $(OPENGL) -o $(TARGET)
	@echo "\x1b[32m\n########################\x1b[0m"

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(SRC_PATH),%.c)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@$(CC) $(CFLAGS) -c $< $(INC_RT) $(INC_LIBFT) $(INC_LIBMLX) -o $@


clean:
	@make clean -C Libft
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C Libft
	@rm -rf $(TARGET)

re: fclean all

r:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(TARGET)
	@make

norme:
	@norminette $(SRC_PATH) $(INC_PATH)
