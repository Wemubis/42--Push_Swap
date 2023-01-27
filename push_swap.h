/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:39 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 17:09:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------- HEADERS -----------------*/
# include "libft/libft.h"
# include <stdio.h>

/*----------------- STRUCTS -----------------*/
typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}		t_stack;

typedef struct s_pile
{
	int		size;
	t_stack	*head;
}		t_pile;

/*------------------ TRUNK ------------------*/
void	push_swap(t_pile *a, t_pile *b);

/*------------------ UTILS ------------------*/
int		check_if_sorted(t_stack *head, int size);
void	errors_process(char *str);
void	check_stack_validity(char **args);
void	replace_data_with_rank(t_pile *a);
void	split_arg_to_stack(t_pile *a, t_pile *b, char *arg);
void	fill_stack(t_pile *a, t_pile *b, int ac, char **av);

/*------------------- SORT ------------------*/
void	sort_big(t_pile *a, t_pile *b);
void	sort_small(t_pile *a, t_pile *b);
void	sort_a(t_pile *a, t_pile *b);

/*------------------- FIND ------------------*/
int		median(t_pile *stack);
int		data_max(t_pile *stack);
int		data_min(t_pile *stack);
int		location(t_stack *top, int rank);
int		theorical_positioning(t_pile *stack, int data);

/*------------------ RULES ------------------*/
void	pa(t_pile *a, t_pile *b);
void	pb(t_pile *a, t_pile *b);
void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);
void	ra(t_pile *a);
void	rb(t_pile *b);
void	rr(t_pile *a, t_pile *b);
void	rra(t_pile *a);
void	rrb(t_pile *b);
void	rrr(t_pile *a, t_pile *b);

/*------------------ STACK ------------------*/
t_stack	*pop(t_pile *stack);
t_stack	*new_element(int data);
void	push_before(t_stack *stack, t_stack *node);
void	free_block(t_stack *node);
void	free_stack(t_stack *stack, int size);

#endif
