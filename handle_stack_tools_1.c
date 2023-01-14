/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_tools_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:16:56 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/14 17:04:53 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int	x;

	x = 0;
	while (stack)
	{
		stack = stack->next;
		x++;
	}
	return (x);
}

void	add_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}
