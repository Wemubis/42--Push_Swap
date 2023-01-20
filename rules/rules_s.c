/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:12:11 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 13:54:01 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile stack)
{
	t_stack	*temp;

	if (stack_is_empty(stack.a) || (*stack.a)->next == NULL)
		return ;
	temp = *stack.a;
	*stack.a = (*stack.a)->next;
	(*stack.a)->next = temp;
	// temp->next = (*stack.a)->next->next;
	write(1, "sa\n", 3);
}

void	sb(t_pile stack)
{
	t_stack	*temp;

	if (stack_is_empty(stack.b) || (*stack.b)->next == NULL)
		return ;
	temp = *stack.b;
	*stack.b = (*stack.b)->next;
	(*stack.b)->next = temp;
	// temp->next = (*stack.b)->next->next;
	write(1, "sb\n", 3);
}

void	ss(t_pile stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}
