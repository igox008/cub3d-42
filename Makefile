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
RM = rm -rf

MLX_MAND = mandatory/MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
OFLAGS_MAND = -Ofast -Wall -Wextra -Werror -g
FLAGS_MAND =  $(MLX_MAND) -Wall -Wextra -Werror -g

LIBDIR_MAND = mandatory/libft
LIBFT_MAND = -I$(LIBDIR_MAND) -L$(LIBDIR_MAND) -lft
NAME = cub3d
MAND_INCLUDES = mandatory/libft/libft.h mandatory/includes/cub3d.h mandatory/g_col/g_collector.h mandatory/gnl/get_next_line.h
MAND_SRC = mandatory/cub3d.c mandatory/g_col/g_collector.c mandatory/gnl/get_next_line.c mandatory/gnl/get_next_line_utils.c \
			mandatory/hooks/hooks.c mandatory/mouvements/movments.c mandatory/parsing/parse00.c mandatory/parsing/parse01.c mandatory/parsing/parse_utils00.c \
			mandatory/parsing/parse_utils01.c mandatory/parsing/utils.c mandatory/rayCasting/raycasting.c mandatory/rayCasting/raycasting_util_I.c \
			mandatory/rayCasting/raycasting_util_II.c mandatory/rendering/render.c mandatory/utils/utils.c mandatory/utils/utils1.c \
			mandatory/utils/utils2.c mandatory/utils/utils3.c

MAND_OBJ = $(MAND_SRC:.c=.o)

MLX_BNS = bonus/MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
OFLAGS_BNS = -Ofast -Wall -Wextra -Werror -g
FLAGS_BNS =  $(MLX_BNS) -Wall -Wextra -Werror -g

LIBDIR_BNS = bonus/libft
LIBFT_BNS = -I$(LIBDIR_BNS) -L$(LIBDIR_BNS) -lft
BNAME = cub3d_bonus
BNS_INCLUDES = bonus/g_col/g_collector_bonus.h bonus/gnl/get_next_line.h bonus/includes/cub3d_bonus.h bonus/libft/libft.h
BNS_SRC = bonus/cub3d_bonus.c bonus/g_col/g_collector_bonus.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c \
		bonus/hooks/hooks_bonus.c bonus/mouvements/movments_bonus.c bonus/parsing/parse00_bonus.c bonus/parsing/parse01_bonus.c \
		bonus/parsing/parse_utils00_bonus.c bonus/parsing/parse_utils01_bonus.c bonus/parsing/utils_bonus.c bonus/rayCasting/raycasting_bonus.c \
		bonus/rayCasting/raycasting_util_II_bonus.c bonus/rayCasting/raycasting_util_I_bonus.c bonus/rendering/render_bonus.c bonus/sfx/run_sfx_bonus.c \
		bonus/utils/utils1_bonus.c bonus/utils/utils2_bonus.c bonus/utils/utils3_bonus.c bonus/utils/utils_bonus.c

BNS_OBJ = $(BNS_SRC:.c=.o)

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(MAND_OBJ) $(MAND_INCLUDES) make_libft_mand
	@echo "$(ORANGE)$(BOLD)building $@...$(RESET)"
	@$(CC) $(FLAGS_MAND) $(MAND_OBJ) -o $@ $(LIBFT_MAND)
	@echo "$(GREEN)$@ is ready to use$(RESET)"

$(BNAME) : $(BNS_OBJ) $(BNS_INCLUDES) make_libft_bns
	@echo "$(ORANGE)$(BOLD)building $@...$(RESET)"
	@$(CC) $(FLAGS_BNS) $(BNS_OBJ) -o $@ $(LIBFT_BNS)
	@echo "$(GREEN)$@ is ready to use$(RESET)"

mandatory/%.o : mandatory/%.c $(MAND_INCLUDES)
	@printf "$(YELLOW)$(BOLD)compiling %s...$(RESET)" "$<"
	@$(CC) $(OFLAGS_MAND) -c $< -o $@
	@printf "\r"
	@printf "\033[2K\r"

bonus/%.o : bonus/%.c $(BNS_INCLUDES)
	@printf "$(YELLOW)$(BOLD)compiling %s...$(RESET)" "$<"
	@$(CC) $(OFLAGS_MAND) -c $< -o $@
	@printf "\r"
	@printf "\033[2K\r"

clean :
	@make -C mandatory/libft/ clean
	@make -C bonus/libft/ clean
	@$(RM) $(MAND_OBJ)
	@$(RM) $(BNS_OBJ)

fclean : clean
	@make -C mandatory/libft/ fclean
	@make -C bonus/libft/ fclean
	@$(RM) $(NAME)
	@$(RM) $(BNAME)

make_libft_mand :
	@make -C mandatory/libft/

make_libft_bns :
	@make -C bonus/libft/


re : fclean all

.PHONY : clean make_libft make_libft_bns