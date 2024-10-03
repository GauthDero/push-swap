# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdero <gdero@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:07:27 by gdero             #+#    #+#              #
#    Updated: 2024/03/19 17:38:36 by gdero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
		string_args.c \
		int_args.c \
		operations.c \
		operations2.c \
		push.c \
		sort_algo.c \
		sort_between.c

OBJECTS = $(SRCS:.c=.o)

HEADER = push_swap.h
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
MAKE_LIBFT = make -s -C ./libft
MAKE_PRINT = make -s -C ./ft_printf
LIBFT = ./libft/libft.a
FTPRINT = ./ft_printf/ft_printf.a

$(NAME): $(OBJECTS)
	$(MAKE_LIBFT)
	$(MAKE_PRINT)
	$(CC) $(CFLAGS) ${OBJECTS} ${LIBFT} ${FTPRINT} -I ${HEADER} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	
all: $(NAME)

clean:
	$(MAKE_LIBFT) clean
	$(MAKE_PRINT) clean
	$(RM) $(OBJECTS) $(OBJBONUS)

fclean: clean
	$(MAKE_LIBFT) fclean
	$(MAKE_PRINT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
