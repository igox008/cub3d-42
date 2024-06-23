# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:30:14 by alaassir          #+#    #+#              #
#    Updated: 2024/06/23 09:21:20 by alaassir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar crs

FILES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memmove.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(FILES:.c=.o)


ALL = $(OBJ)

NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "$(ORANGE)$(BOLD)building $@...$(RESET)"
	@$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@printf "$(YELLOW)$(BOLD)compiling %s...$(RESET)" "$<"
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "\r"
	@printf "\033[2K\r"

clean:
	@$(RM) $(ALL)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
