/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:49 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 18:01:40 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_is_empty(stack.a) || stack.a->next == NULL)
		return ;
	temp = stack.a;
	last = last_element(stack.a);
	last->next = temp;
	while (stack.a->next->next)
		stack.a = stack.a->next;
	stack.a->next = NULL;
	write(1, "rra\n", 3);
}

void	rrb(t_pile stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_is_empty(stack.b) || stack.b->next == NULL)
		return ;
	temp = stack.b;
	last = last_element(stack.b);
	last->next = temp;
	while (stack.b->next->next)
		stack.b = stack.b->next;
	stack.b->next = NULL;
	write(1, "rrb\n", 3);
}

void	rrr(t_pile stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 3);
}
