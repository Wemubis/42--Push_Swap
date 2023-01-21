/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 20:25:06 by mle-boud         ###   ########.fr       */
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
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	push_before(t_stack *stack, t_stack *node)
{
	if (!node)
		return ;
	if (!stack)
	{
		stack = node;
		return ;
	}
	node->prev = stack->prev;
	node->next = stack;
	if (node->prev != NULL)
		node->prev->next = node;
	if (node->next != NULL)
		node->next->prev = node;
}

void	push_after(t_stack *stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->prev = stack;
	node->next = stack->next;
	if (node->prev != NULL)
		node->prev->next = node;
	if (node->next != NULL)
		node->next->prev = node;
}

t_stack	*pop(t_pile *stack)
{
	t_stack	*tmp;

	tmp = stack->first;
	if (stack->size == 1)
		stack->first = NULL;
	else
	{
		stack->first = stack->first->next;
		stack->first->prev = stack->first->prev->prev;
		stack->first->prev->next = stack->first;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

t_stack	*last_element(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return (NULL);
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
