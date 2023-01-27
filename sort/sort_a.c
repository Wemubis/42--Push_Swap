/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:31:02 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/25 23:31:02 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_pile *a, t_pile *b)
{
	int	ref;

	while (theorical_positioning(a, b->head->data) != 0)
	{
		ref = theorical_positioning(a, b->head->data);
		if (ref == -1 && b->head->data > a->head->prev->data)
			break ;
		if (ref < 0 || (ref > 0 && ref > median(a)))
			rra(a);
		if (ref > 0 && ref <= median(a))
			ra(a);
	}
	pa(a, b);
}
