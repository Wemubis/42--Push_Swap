/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:34:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/09 16:45:29 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_a(t_pile *a, t_pile *b, int ch_size[2])
{
	int	i;
	int	val_ch[10];

	i = -1;
	while (++i < 9)
		val_ch[i] = ch_size[0] / 2 * (i + 1);
	val_ch[i] = b->size;
	while (val_ch[i])
	{
		ch_size[1] = ch_size[0] / 2;
		while (ch_size[1] && b->size)
		{
			if (i == 9)
			{
				first_chunk(a, b);
				break ;
			}
			lil_lil_sort(a, b);
			sort_chunk_a(a, b);
			ch_size[1]--;
		}
		if (check_if_sorted(a) == 0)
			sort_a(a, b, val_ch, i);
		i--;
	}
}

static void	after_pb(t_pile *a, t_pile *b, int chunk_size, int val)
{
	int	half;

	half = chunk_size / 2;
	val -= half;
	if ((a->head->data && a->head->prev->data)>= val && b->head->data < val)
		rr(a, b);
	else if ((a->head->data && a->head->prev->data) >= val)
		ra(a, 0);
	else if (b->head->data < val)
	{
		rb(b, 0);
		if (a->head->prev->data < val)
			rra(a, 0);
	}
}

static void	last_chunk(t_pile *a, t_pile *b, int val[5])
{
	int	half;

	half = val[4] - val[3] + 1;
	while (a->size)
	{
		pb(a, b);
		if (!a->head)
			return ;
		after_pb(a, b, half, val[4]);
	}
}

static void	put_in_b(t_pile *a, t_pile *b, int ch_size[2], int val_ch[5])
{
	int	i;
	
	i = -1;
	while (val_ch[++i])
	{
		if (a->size && i == 4)
		{
			last_chunk(a, b, val_ch);
			return ;
		}
		ch_size[1] = ch_size[0];
		while (ch_size[1] && a->size)
		{
			if (a->head->data < val_ch[i])
			{
				pb(a, b);
				after_pb(a, b, ch_size[0], val_ch[i]);
				ch_size[1]--;
			}
			else if (a->head->prev->data < val_ch[i])
				rra(a, 0);
			else
				ra(a, 0);
		}
	}
}

void	sort_big(t_pile *a, t_pile *b)
{
	int	i;
	int	chunk_size[2];
	int	value_chunk[5];

	if (check_if_sorted(a) == 1)
		return ;
	chunk_size[0] = a->size / 5;
	i = -1;
	while (++i < 4)
		value_chunk[i] = chunk_size[0] * (i + 1);
	value_chunk[i] = a->size;
	put_in_b(a, b, chunk_size, value_chunk);
	put_in_a(a, b, chunk_size);
}
