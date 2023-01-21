/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:49 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 13:53:13 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_is_empty(stack.a) || (*stack.a)->next == NULL)
		return ;
	last = last_element(stack.a);
	tmp = *stack.a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack.a;
	write(1, "rra\n", 3);
}

// see if what's on top is okay
void	rrb(t_pile stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack_is_empty(stack.b) || (*stack.b)->next == NULL)
		return ;
	tmp = *stack.b;
	last = last_element(stack.b);
	last->next = tmp;
	while ((*stack.b)->next->next)
		*stack.b = (*stack.b)->next;
	(*stack.b)->next = NULL;
	write(1, "rrb\n", 3);
}

void	rrr(t_pile stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 3);
}
