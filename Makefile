# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:30:13 by mle-boud          #+#    #+#              #
#    Updated: 2023/01/14 15:12:28 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = pipex.h

################ SRCS ################
SRCS = 

################ OBJS ################
OBJS = $(patsubst %.c,%.o,$(SRCS))

################ PHONY ################
.PHONY: all clean fclean re $(NAME)

################ RULES ################
all: otherMakefile $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $^ -o $@

otherMakefile:
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@ 

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all