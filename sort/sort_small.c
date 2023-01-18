/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 17:35:06 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_pile stack)
{
	
}

void	sort_small(t_pile stack)
{
	int	size_a;

	size_a = size_stack(stack.a);
	set_ranking(stack.a);
	if (size_a > 3)
		sort_in_b(stack);
	while (!check_if_sorted(stack.a))
	{
		if (stack.a->rank == (size_a - 1))
			ra(stack);
		else if (stack.a->rank > stack.a->next->rank)
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
