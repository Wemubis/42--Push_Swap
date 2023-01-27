/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:59 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 13:19:29 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile *a)
{
	if (a->head->next == a->head)
		return ;
	a->head = a->head->next;
	write(1, "ra\n", 3);
}

void	rb(t_pile *b)
{
	if (b->head->next == b->head)
		return ;
	b->head = b->head->next;
	write(1, "rb\n", 3);
}

void	rr(t_pile *a, t_pile *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
