/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:16:56 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 17:14:26 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
}

void	push_stack(t_stack *stack, t_stack *top)
{
	if (!top)
		return ;
	top->next = stack;
	stack = top;
}

void	pop_stack(t_stack *stack)
{
	t_stack	*temp;

	if (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		temp->next = NULL;
		free(temp);
	}
}

t_stack	*last_element(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack == NULL);
}
