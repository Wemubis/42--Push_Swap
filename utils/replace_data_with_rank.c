/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_data_with_rank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:46:21 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/04 00:04:54 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_rank(t_pile *a, t_stack *top)
{
	int		j;
	int		rank;
	t_stack	*tmp;

	j = 0;
	rank = 0;
	tmp = a->head;
	while (j < a->size)
	{
		if (top->data > tmp->data)
			rank++;
		tmp = tmp->next;
		j++;
	}
	return (rank);
}

void	replace_data_with_rank(t_pile *a)
{
	int		*tab_rank;
	int		i;

	tab_rank = malloc(sizeof(int *) * a->size);
	if (!tab_rank)
		errors_process("malloc fail");
	i = 0;
	while (i < a->size)
	{
		tab_rank[i] = find_rank(a, a->head);
		printf("a->head->data=%d tab_rank[i]=%d\n", a->head->data, tab_rank[i]);
		a->head = a->head->next;
		i++;
	}
	i = -1;
	while (++i < a->size)
		a->head->data = tab_rank[i];
	free(tab_rank);
}
