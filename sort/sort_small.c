/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/17 14:16:30 by mle-boud         ###   ########.fr       */
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
		else if (location(a, x) < 2)
			sa(a, 0);
		else if (location(a, x) > 2)
			rra(a, 0);
		else
			ra(a, 0);
		if (check_if_sorted(a))
			break ;
	}
}

void	sort_small(t_pile *a, t_pile *b)
{
	int	save_size;

	save_size = a->size;
	if (a->size > 3)
		sort_in_b(a, b);
	while (check_if_sorted(a) == 0)
	{
		if (a->head->data == data_max(a))
			ra(a, 0);
		else if (a->head->data > a->head->next->data)
			sa(a, 0);
		else
			rra(a, 0);
	}
	while (save_size > 3)
	{
		pa(a, b);
		save_size--;
	}
}
