/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:34:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/06 02:18:53 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_a(t_pile *a, t_pile *b, int chunk_size[2])
{
	int	i;
	int	value_chunk[10];

	i = -1;
	while (++i < 9)
		value_chunk[i] = chunk_size[0] / 2 * (i + 1);
	value_chunk[i] = b->size;
	while (value_chunk[i])
	{
		chunk_size[1] = chunk_size[0] / 2;
		while (chunk_size[1] && b->size)
		{
			if (i % 2 == 1)
				sort_chunk_a(a, b);
			else if (i % 2 == 0)
			{
				rrb(b, 0);
				sort_chunk_a(a, b);
			}
			chunk_size[1]--;
		}
		if (!check_if_sorted(a))
			sort_a(a);
		i--;
	}
}

static void	after_pb(t_pile *a, t_pile *b, int chunk_size, int val_chunk)
{
	int	half;
	int	b_h_d;
	int	b_h_n_d;
	int	b_h_n_n_d;

	half = chunk_size / 2;
	b_h_d = b->head->data;
	b_h_n_d = b->head->next->data;
	b_h_n_n_d = b->head->next->next->data;
	if (a->head->data > val_chunk && b_h_d < (val_chunk - half))
		rr(a, b);
	else if (a->head->data < val_chunk && b_h_d < (val_chunk - half))
		rb(b, 0);
	else if (a->head->data > val_chunk)
		ra(a, 0);
	else if  (b_h_d < b_h_n_d && b_h_d < b_h_n_n_d)
	{
		rb(b, 0);
		sb(b, 0);
		rrb(b, 0);
	}
	else if (b_h_d < b_h_n_d && b_h_d > b_h_n_n_d)
		sb(b, 0);
}

static void	put_in_b(t_pile *a, t_pile *b, int chunk_size[2], int value_chunk[5])
{
	int	i;
	
	i = 0;
	while (value_chunk[i])
	{
		chunk_size[1] = chunk_size[0];
		while (chunk_size[1] && a->size)
		{
			if (a->head->data < value_chunk[i])
			{
				pb(a, b);
				after_pb(a, b, chunk_size[0], value_chunk[i]);
			}
			chunk_size[1]--;
		}
		if (a->size != 0 && i == 4)
		{
			while (a->size > 0)
			{
				pb(a, b);
				if (!a->head)
					break ;
				after_pb(a, b, chunk_size[0], value_chunk[i]);
			}
		}
		i++;
	}
}

void	sort_big(t_pile *a, t_pile *b)
{
	int	i;
	int	chunk_size[2];
	int	value_chunk[5];

	printf("before the chunking");
	if (check_if_sorted(a))
		return ;
	printf("after check sorted");
	chunk_size[0] = a->size / 5;
	i = -1;
	while (++i < 4)
		value_chunk[i] = chunk_size[0] * (i + 1);
	value_chunk[i] = a->size;
	put_in_b(a, b, chunk_size, value_chunk);
	write(1, "after put in b\n", 15);
	// NOW I NEED TO CHECK PUT IN A CAUSE SOME PB IF SIZE < 10
	// WITH A CONDITION "IF ... < 10" USE SOMETHING ELSE
	put_in_a(a, b, chunk_size);
	printf("after put in a");
}
