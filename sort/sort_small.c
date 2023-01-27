/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:53:40 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 20:54:19 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_pile *a, t_pile *b)
{
	t_stack	*tmp;
	int		x;

	x = 0;
	tmp = a->head;
	while (a->size > 3)
	{
		if (tmp->data == x)
		{
			pb(a, b);
			x++;
		}
		else if (find_location(tmp, x) < (a->size / 2))
			sa(a);
		else
			ra(a);
	}
	if (check_if_sorted(b->head, b->size))
		sb(b);
}

void	sort_small(t_pile *a, t_pile *b)
{
	t_stack	*tmp;

	replace_data_with_rank(a);
	if (a->size > 3)
		sort_in_b(a, b);
	write(1, "sort in b done\n", 15);
	exit(EXIT_SUCCESS);
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
