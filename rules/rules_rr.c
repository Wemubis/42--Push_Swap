/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:49 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/06 01:31:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *a)
{
	if (a->head->prev == a->head)
		return ;
	a->head = a->head->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_pile *b)
{
	if (b->head->prev == b->head)
		return ;
	b->head = b->head->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_pile *a, t_pile *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
