/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:14:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 13:19:19 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile *a, t_pile *b)
{
	if (b->head == NULL)
		return ;
	push_before(a->head, pop(b));
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_pile *a, t_pile *b)
{
	if (a->head == NULL)
		return ;
	push_before(b->head, pop(a));
	b->size++;
	write(1, "pb\n", 3);
}
