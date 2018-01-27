# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:55:19 by vguillem          #+#    #+#              #
#    Updated: 2018/01/27 08:23:51 by vguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS =				main.c \
					ft_mparse.c \
					ft_mexe.c \
					ft_myenv.c \
					ft_mprint.c \
					ft_msetenv.c \
					ft_mcd.c \
					ft_mecho.c \
					ft_menv.c \
					ft_munsetenv.c \
					ft_signal.c \
					ft_metoc.c \
					ft_mcdutil.c \
					ft_mutils.c \


INCLUDE =	libft/includes/libft.h \
			libft/printf/libftprintf.h \
			libft/gnl/get_next_line.h \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(OBJS) -L libft/ -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $? -c -o $@

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
