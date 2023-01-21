/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 18:05:18 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_pile stack)
{
	t_stack	*tmp;
	int		size_a;
	int		x;

	x = 0;
	size_a = size_stack(stack.a);
	tmp = *stack.a;
	while (size_stack(stack.a) > 3)
	{
		if (tmp->rank == x)
		{
			pb(stack);
			x++;
		}
		if (find_location(stack.a, x) < size_a)
			sa(stack);
		else
			ra(stack);
	}
	if (!check_if_sorted(stack.b))
		sb(stack);
}

void	sort_small(t_pile stack)
{
	t_stack	*tmp;
	int		size_a;

	size_a = size_stack(stack.a);
	set_ranking(stack.a);
	if (size_a > 3)
		sort_in_b(stack);
	tmp = *stack.a;
	while (!check_if_sorted(stack.a))
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
