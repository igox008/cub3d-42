NAME = cub3d
SRCS = ./parcing/g_col.c ./main.c ./parcing/get_next_line.c ./parcing/libft.c
OBJS    = $(SRCS:.c=.o)

CFLAGS 	=   -Wall -Wextra -Werror
RM 		= @rm -f
all : $(NAME)

$(NAME):$(OBJS)
	@echo "Linking $(NAME)"
	@$(CC)  $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	@echo "Compiling $<"
	@$(CC)  $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean