/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/06 01:32:22 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_pile *a, t_pile *b)
{
	int		x;

	x = 0;
	while (a->size > 3)
	{
		if (a->head->data == x)
		{
			pb(a, b);
			x++;
		}
		else if (location(a->head, x) < (a->size / 2))
			sa(a);
		else
			ra(a);
	}
	if (check_if_sorted(b))
		sb(b);
}

void	sort_small(t_pile *a, t_pile *b)
{
	int	save_size;

	save_size = a->size;
	if (a->size > 3)
		sort_in_b(a, b);
	while (check_if_sorted(a) == 0)
	{
		if (a->head->data == save_size - 1)
			ra(a);
		else if (a->head->data > a->head->next->data)
			sa(a);
		else
			rra(a);
	}
	while (save_size > 3)
	{
		pa(a, b);
		save_size--;
	}
}
