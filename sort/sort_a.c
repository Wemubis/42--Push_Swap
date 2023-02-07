/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:31:02 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/07 01:12:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk_a(t_pile *a, t_pile *b)
{
	int	ref;

	while (theorical_positioning(a, b->head->data) != 0)
	{
		ref = theorical_positioning(a, b->head->data);
		if (ref == -1 && b->head->data > a->head->prev->data)
			break ;
		if (ref < 0 || (ref > 0 && ref > median(a)))
			rra(a, 0);
		if (ref > 0 && ref <= median(a))
			ra(a, 0);
	}
	pa(a, b);
}

void	sort_a(t_pile *a)
{
	while (a->head->data != data_min(a))
	{
		if (location(a, data_max(a)) > median(a))
			rra(a, 0);
		else
			ra(a, 0);
	}
}
