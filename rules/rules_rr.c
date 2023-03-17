/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:49 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/17 14:16:14 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *a, int bool)
{
	if (a->head->prev == a->head)
		return ;
	a->head = a->head->prev;
	if (bool == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_pile *b, int bool)
{
	if (b->head->prev == b->head)
		return ;
	b->head = b->head->prev;
	if (bool == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_pile *a, t_pile *b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}
