/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:59 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 17:24:52 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_is_empty(stack.a) || (*stack.a)->next == NULL)
		return ;
	temp = *stack.a;
	*stack.a = (*stack.a)->next;
	last = last_element(stack.a);
	last->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_pile stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_is_empty(stack.b) || (*stack.b)->next == NULL)
		return ;
	temp = *stack.b;
	*stack.b = (*stack.b)->next;
	last = last_element(stack.b);
	last->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_pile stack)
{
	ra(stack);
	rb(stack);
	write(1, "rr\n", 3);
}
