# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:30:13 by mle-boud          #+#    #+#              #
#    Updated: 2023/01/21 19:55:05 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = push_swap.h

################ DIRS ################
DIR_RULES = rules/
DIR_SORT = sort/
DIR_UTILS = utils/

################ SRCS ################
SRCS = main.c push_swap.c \

RULES = rules_p.c rules_r.c rules_rr.c rules_s.c \

SORT = sort_big.c sort_small.c sort_a.c \

UTILS = check.c create_stack.c errors_process.c replace_data_with_rank.c \
		stack_tools.c find.c \

############ DIRS + SRCS #############
SRCS_RULES = $(addprefix $(DIR_RULES), $(RULES))
SRCS_SORT = $(addprefix $(DIR_SORT), $(SORT))
SRCS_UTILS = 	$(addprefix $(DIR_UTILS), $(UTILS))

################ OBJS ################
OBJS_SRCS = $(patsubst %.c, %.o,$(SRCS))
OBJS_RULES =  $(patsubst %.c,%.o,$(SRCS_RULES))
OBJS_SORT =  $(patsubst %.c,%.o,$(SRCS_SORT))
OBJS_UTILS =  $(patsubst %.c,%.o,$(SRCS_UTILS))
OBJS = $(OBJS_SRCS) $(OBJS_RULES) $(OBJS_SORT) $(OBJS_UTILS)

################ PHONY ################
.PHONY: all clean fclean re $(NAME)

################ RULES ################
all: otherMakefile $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $^ -fsanitize=address -g3 -o $@

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