# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 18:53:48 by rzimaeva          #+#    #+#              #
#    Updated: 2025/11/29 19:41:34 by rzimaeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

EXEC = main

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putptr.c \
	   ft_print_decimal.c \
	   ft_print_percent.c \
	   ft_puthex.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
LDFLAGS = -L. -lftprintf

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(NAME) a été créée, bv"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re