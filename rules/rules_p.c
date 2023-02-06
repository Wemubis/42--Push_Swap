/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:14:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/06 01:07:27 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_to_other_stack(t_pile *from, t_pile *to)
{
	t_stack *poped;
	t_stack *stock;

	if (!from)
		return;
	poped = pop(from);
	if (to->head)
	{
		stock = to->head->prev;
		to->head->prev = poped;
		to->head->prev->next = to->head;
		to->head->prev->prev = stock;
		to->head->prev->prev->next = poped;
		to->head = to->head->prev;
	}
	else
		to->head = poped;
}

void	pa(t_pile *a, t_pile *b)
{
	if (!b->head)
		return ;
	push_to_other_stack(b, a);
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_pile *a, t_pile *b)
{
	if (!a->head)
		return ;
	push_to_other_stack(a, b);
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}
