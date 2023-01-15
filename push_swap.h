/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:39 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 17:14:19 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------- HEADERS -----------------*/
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	push_swap(t_pile stack);

/*------------------ UTILS ------------------*/
void	errors_process(char *str);
t_stack	**split_arg_to_stack(t_stack **a, char *arg);
t_stack	**fill_stack(t_stack **a, int ac, char **av);

/*------------------ STACK ------------------*/
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}		t_stack;

typedef struct s_pile
{
	t_stack	**a;
	t_stack	**b;
}		t_pile;

t_stack	*new_element(int data);
t_stack	*last_element(t_stack **stack);
void	push_stack(t_stack **stack, t_stack *top);
void	pop_stack(t_stack **stack);
int		stack_is_empty(t_stack **stack);

#endif