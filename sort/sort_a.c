/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:31:02 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/12 14:14:06 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lil_lil_sort(t_pile *a, t_pile *b)
{
	t_stack	*b_h_p;

	b_h_p = b->head->prev;
	if (b->head->data < b_h_p->data && b_h_p->data < a->head->prev->data)
		if (a->head->prev->data != data_max(a))
			rrr(a, b);
	if (b->head->data < b->head->prev->data)
		rrb(b, 0);
}

void	first_chunk(t_pile *a, t_pile *b)
{
	int	k[2];

	k[1] = 0;
	k[0] = b->size - (b->size / 10 * 9);
	while (k[1] < k[0])
	{
		if (location(b, data_max(b)) == 0)
		{
			pa(a, b);
			k[1]++;
		}
		else if (location(b, data_max(b)) > median(b))
			rrb(b, 0);
		else
			rb(b, 0);
	}
}

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

static void	sort_a_continued(t_pile *a, t_pile *b, int val_1, int val_2)
{
	if (location(a, data_max(a)) > median(a))
	{
		if (b->head->prev->data > val_1 && b->head->prev->data < val_2)
			rrr(a, b);
		else
			rra(a, 0);
	}
	else
		ra(a, 0);
}

void	sort_a(t_pile *a, t_pile *b, int val_ch[10], int i)
{
	if (i > 1 && i % 2 == 1)
	{
		while (a->head->data != data_min(a) && !check_if_sorted(a))
			sort_a_continued(a, b, val_ch[i - 2], val_ch[i - 1]);
	}
	else
	{
		while (a->head->data != data_min(a) && !check_if_sorted(a))
		{
			if (location(a, data_max(a)) > median(a))
				rra(a, 0);
			else
				ra(a, 0);
		}
	}
}
