/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/12 14:14:25 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_element(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error();
	new->data = data;
	new->prev = new;
	new->next = new;
	return (new);
}

void	push_before(t_stack *stack, t_stack *to_add)
{
	if (!stack || !to_add)
		return ;
	to_add->prev = stack->prev;
	to_add->next = stack;
	to_add->prev->next = to_add;
	to_add->next->prev = to_add;
}

t_stack	*pop(t_pile *stack)
{
	t_stack	*tmp;

	tmp = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = stack->head->prev->prev;
		stack->head->prev->next = stack->head;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	free_block(t_stack *node)
{
	if (node->data != node->next->data)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
}

void	free_stack(t_stack *head, int size)
{
	if (!head)
		return ;
	while (head->data != head->next->data)
	{
		head = head->next;
		free_block(head->prev);
		size--;
	}
	free_block(head);
	size = 0;
}
