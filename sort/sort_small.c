/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 18:06:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_in_b(t_pile *a, t_pile *b)
{
	t_stack	*tmp;
	int		size;
	int		x;

	x = 0;
	size = a->size;
	tmp = a->head;
	while (a->size > 3)
	{
		if (tmp->data == x)
		{
			pb(a, b);
			x++;
		}
		if (find_location(a->head, x) < (a->size / 2))
			sa(a);
		else
			ra(a);
		size--;
	}
	if (check_if_sorted(b->head, b->size))
		sb(b);
}

void	sort_small(t_pile *a, t_pile *b)
{
	t_stack	*tmp;

	replace_data_with_rank(a);
	exit(EXIT_SUCCESS);
	if (a->size > 3)
		sort_in_b(a, b);
	tmp = a->head;
	while (!check_if_sorted(a->head, a->size))
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
