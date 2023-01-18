/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:39 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 16:11:17 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------- HEADERS -----------------*/
# include "libft/libft.h"

/*------------------ TRUNK ------------------*/
void	push_swap(t_pile stack);

/*------------------ UTILS ------------------*/
void	errors_process(char *str);
int		check_if_sorted(t_stack *stack);
void	check_stack_validity(char **args);
void	set_ranking(t_stack *stack);
t_stack	*split_arg_to_stack(t_stack *a, char *arg);
t_stack	*fill_stack(t_stack *a, int ac, char **av);

/*------------------- SORT ------------------*/
void	sort_small(t_pile stack);

/*------------------ RULES ------------------*/
void	pa(t_pile stack);
void	pb(t_pile stack);
void	sa(t_pile stack);
void	sb(t_pile stack);
void	ss(t_pile stack);
void	ra(t_pile stack);
void	rb(t_pile stack);
void	rr(t_pile stack);
void	rra(t_pile stack);
void	rrb(t_pile stack);
void	rrr(t_pile stack);

/*------------------ STACK ------------------*/
typedef struct s_stack
{
	int				data;
	int				rank;
	struct s_stack	*next;
}		t_stack;

typedef struct s_pile
{
	t_stack	*a;
	t_stack	*b;
}		t_pile;

t_stack	*new_element(int data);
t_stack	*last_element(t_stack *stack);
void	push_stack(t_stack *stack, t_stack *top);
void	pop_stack(t_stack *stack);
int		size_stack(t_stack *stack);
int		stack_is_empty(t_stack *stack);

#endif