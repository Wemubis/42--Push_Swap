/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:39 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/14 17:19:47 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------- HEADERS -----------------*/
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	push_swap(t_stack **a, t_stack **b, t_stack *top, t_stack *bottom);

/*------------------ UTILS ------------------*/
void	errors_process(char *str);
t_stack	**split_arg_to_stack(char *arg);
t_stack	**fill_stack(int ac, char **av);

/*------------------ STACK ------------------*/
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}		t_stack;

t_stack	*new_element_stack(int data);
int		stack_size(t_stack *stack);
void	add_stack(t_stack **stack, t_stack *new);
int		stack_is_empty(t_stack **stack);
void	del_top_stack(t_stack *elem);
void	stack_clear(t_stack **stack);

#endif