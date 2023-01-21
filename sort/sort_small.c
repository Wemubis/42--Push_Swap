/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 20:21:22 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_pile *a, t_pile *b)
{
	t_stack	*tmp;
	int		size;
	int		x;

	x = 0;
	size = a->size;
	tmp = a->first;
	while (a->size > 3)
	{
		if (tmp->data == x)
		{
			pb(a, b);
			x++;
		}
		if (find_location(a->first, x) < size / 2)
			sa(a);
		else
			ra(a);
		a->size--;
	}
	if (check_if_sorted(b))
		sb(b);
}

void	sort_small(t_pile *a, t_pile *b)
{
	t_stack	*tmp;

	replace_data_with_rank(a);
	if (a->size > 3)
		sort_in_b(a, b);
	tmp = a->first;
	while (!check_if_sorted(a))
	{
		if (tmp->data == (a->size - 1))
			ra(a);
		else if (tmp->data > tmp->next->data)
			sa(a);
		else
			rra(a);
	}
	while (a->size > 3)
	{
		pa(a, b);
		a->size--;
	}
}
