# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:30:13 by mle-boud          #+#    #+#              #
#    Updated: 2023/03/17 14:14:59 by mle-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
RM = rm -f

D_HDRS = .

CFLAGS = -Wall -Wextra -Werror -g3
DEPFLAGS = -MMD -MP $(foreach F, $(D_HDRS),-I$(F))

################ DIRS ################
DIR_RULES = rules/
DIR_SORT = sort/
DIR_UTILS = utils/

################ SRCS ################
MAIN = main.c push_swap.c \

RULES = rules_p.c rules_r.c rules_rr.c rules_s.c \

SORT = sort_big.c sort_inf_ten.c sort_small.c sort_a.c \

UTILS = check.c create_stack.c errors_process.c replace_data_with_rank.c \
		stack_tools.c find.c \

############ DIRS + SRCS #############
SRCS_RULES = $(addprefix $(DIR_RULES), $(RULES))
SRCS_SORT = $(addprefix $(DIR_SORT), $(SORT))
SRCS_UTILS = 	$(addprefix $(DIR_UTILS), $(UTILS))
SRCS = $(SRCS_RULES) $(SRCS_SORT) $(SRCS_UTILS) $(MAIN)

################ OBJS + DEPS ################
OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

################ PHONY ################
.PHONY: all clean fclean re $(NAME)

################ RULES ################
all: lib $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $^ -o $@

lib:
	@make -C libft --no-print-directory

-include $(DEPS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@ 

clean:
	make -C libft clean
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all
