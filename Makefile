# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:30:13 by mle-boud          #+#    #+#              #
#    Updated: 2023/01/15 13:54:41 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = push_swap.h

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