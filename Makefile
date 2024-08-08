RESET=\033[0m
BOLD=\033[1m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
ORANGE=\033[38;5;208m

BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_BLUE=\033[44m
BG_MAGENTA=\033[45m
BG_CYAN=\033[46m
BG_WHITE=\033[47m

CC = cc
# OFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
FLAGS = -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g
RM = rm -rf


LIBDIR = libft
LIBFT = -I$(LIBDIR) -L$(LIBDIR) -lft
NAME = cub3d
MAND_INCLUDES = libft/libft.h includes/cub3d.h g_col/g_collector.h gnl/get_next_line.h
MAND_SRC = rayCasting/raycasting.c  rayCasting/raycasting_util_I.c rayCasting/raycasting_util_II.c rayCasting/draw.c cub3d.c parsing/parse00.c g_col/g_collector.c gnl/get_next_line.c gnl/get_next_line_utils.c parsing/parse_utils01.c \
			parsing/parse_utils00.c parsing/parse01.c parsing/utils.c rayCasting/utils.c rayCasting/utils1.c

MAND_OBJ = $(MAND_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(MAND_OBJ) $(MAND_INCLUDES) make_libft
	@echo "$(ORANGE)$(BOLD)building $@...$(RESET)"
	@$(CC) $(FLAGS) $(MAND_OBJ) -o $@ $(LIBFT)
	@echo "$(GREEN)$@ is ready to use$(RESET)"

%.o : %.c $(MAND_INCLUDES)
	@printf "$(YELLOW)$(BOLD)compiling %s...$(RESET)" "$<"
	@$(CC) $(OFLAGS) -c $< -o $@
	@printf "\r"
	@printf "\033[2K\r"

clean :
	@make -C libft/ clean
	@$(RM) $(MAND_OBJ)

fclean : clean
	@make -C libft/ fclean
	@$(RM) $(NAME)

make_libft :
	@make -C libft/


re : fclean all

.PHONY : clean make_libft