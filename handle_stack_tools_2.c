/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_tools_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:17:43 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/14 17:05:32 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_empty(t_stack **stack)
{
	return (!*stack);
}

void	del_top_stack(t_stack *elem)
{
	free(elem);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*elem;
	t_stack	*next;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = NULL;
		return ;
	}
	elem = *stack;
	while (elem)
	{
		next = elem->next;
		del_top_stack(elem);
		elem = next;
	}
	*stack = NULL;
}
