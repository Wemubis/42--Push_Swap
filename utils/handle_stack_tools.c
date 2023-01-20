/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:16:56 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 15:30:55 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	push_stack(t_stack **stack, int data)
{
	t_stack	*temp;

	temp = new_element(data);
	if (!temp)
		exit(EXIT_FAILURE);
	if (stack_is_empty(stack))
	{
		temp->next = NULL;
		*stack = temp;
	}
	else
	{
		temp->next = *stack;
		*stack = temp;
	}
}

void	pop_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack)
	{
		temp = stack[0];
		stack[0] = stack[0]->next;
		temp->next = NULL;
		free(temp);
	}
}

t_stack	*last_element(t_stack **stack)
{
	int	i;

	i = -1;
	if (!*stack)
		return (NULL);
	while (stack[++i]->next != NULL)
		stack[i] = stack[i]->next;
	return (stack[i]);
}

int	stack_is_empty(t_stack **stack)
{
	if (*stack == NULL)
		return (1);
	return (0);
}
