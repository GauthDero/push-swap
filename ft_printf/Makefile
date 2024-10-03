# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdero <gdero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:47:07 by gdero             #+#    #+#              #
#    Updated: 2024/03/04 15:03:58 by gdero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
		ft_putnbr.c \
		hexa.c

OBJECTS = $(SRCS:.c=.o)

HEADER = ft_printf.h
NAME = ft_printf.a
LIBCREATE = ar -rc
LIBUPDATE = ranlib
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f


.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I $(HEADER)
$(NAME): $(OBJECTS)
	$(LIBCREATE) $(NAME) $(OBJECTS)
	$(LIBUPDATE) $(NAME)

bonus: $(OBJBONUS)
	$(LIBCREATE) $(NAME) $(OBJBONUS)
	$(LIBUPDATE) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
