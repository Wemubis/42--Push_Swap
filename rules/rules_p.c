/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:14:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/01 17:23:51 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_to_other_stack(t_pile *from, t_stack *to)
{
	t_stack *poped;
	t_stack *stock;

	if (!from)
		return;
	poped = pop(from);
	if (to)
	{
		stock = to->prev;
		to->prev = poped;
		to->prev->next = to;
		to->prev->prev = stock;
		to->prev->prev->next = poped;
		to = to->prev;
	}
	else
	{
		to = poped;
		to->next = to;
		to->prev = to;
	}
}

void	pa(t_pile *a, t_pile *b)
{
	if (!b->head)
		return ;
	push_to_other_stack(b, a->head);
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_pile *a, t_pile *b)
{
	if (!a->head)
		return ;
	push_to_other_stack(a, b->head);
	b->size++;
	write(1, "pb\n", 3);
}
