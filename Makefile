TARGET = rt_v1

#Sources
SRC_NAME = main.c set_object.c sphere.c exit.c matrice.c
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
LIBMLX = -L./minilibx/ -lmlx
#############

#Frameworks
APPKIT = -framework Appkit
OPENGL = -framework Opengl
############

#Flags
CFLAGS = -Wall -Wextra -Werror 
CC = gcc

DEBUGFLAG1 = -g3
DEBUGFLAG2 = -fsanitize=address
#############
cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"

all: $(TARGET)
	@$(call cyan,"Hello world !")

.PHONY: libmlx libft obj clean fclean re

$(TARGET): $(OBJ)
	@echo "\n######## 1/3 libft ########"
	@make -C $(LIBFT_PATH)
	@echo "\n########################"
	@echo "\n######## 2/3 libmlx ########"
	@make -C $(LIBMLX_PATH)
	@echo "\n########################"
	@echo "\n######## 3/3 Rt_v1 ########"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(APPKIT) $(OPENGL) -o $(TARGET)
	@echo "\n########################"

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(SRC_PATH),%.c)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -c $< $(INC_RT) $(INC_LIBFT) $(INC_LIBMLX) -o $@


clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(TARGET)

re: fclean all
