/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 19:10:11 by mle-boud         ###   ########.fr       */
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
		if (tmp->rank == x)
		{
			pb(a, b);
			x++;
		}
		if (find_location(a->first, x) < size)
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
	int		size_a;

	size_a = size_stack(stack.a);
	set_ranking(stack.a);
	if (size_a > 3)
		sort_in_b(stack);
	tmp = *stack.a;
	while (!check_if_sorted(a))
	{
		if (tmp->rank == (size_a - 1))
			ra(stack);
		else if (tmp->rank > tmp->next->rank)
			sa(stack);
		else
			rra(stack);
	}
	while (size_a > 3)
	{
		pa(stack);
		size_a--;
	}
}
