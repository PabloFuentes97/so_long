NAME = so_long
NAME_BONUS = so_long_bonus

SRC = so_long.c get_next_line.c get_next_line_utils.c utils_bonus.c checker.c check_functions.c create_map.c graph.c lst_functions.c pathfinding_utils.c pathfinding.c inputs.c images.c images2.c info.c draw_map.c player_movement.c \

SRC_BONUS = animate_bonus.c create_map_bonus.c get_next_line_bonus.c images2_bonus.c pathfinding_bonus.c animate_player_bonus.c draw_map_bonus.c \
get_next_line_utils_bonus.c info_bonus.c pathfinding_utils_bonus.c check_functions_bonus.c  graph_bonus.c inputs_bonus.c so_long_bonus.c utils_bonus.c \
checker_bonus.c images_bonus.c lst_functions_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME) 
bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
		gcc -Wall -Werror -Wextra -c $(SRC)
		gcc -Wall -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
		gcc -Wall -Werror -Wextra -c $(SRC_BONUS)
		gcc -Wall -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ_BONUS) -o $(NAME_BONUS)


clean:
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re