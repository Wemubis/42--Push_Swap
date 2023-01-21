/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ranking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:55:25 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 14:02:58 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ranking(t_stack **stack)
{
	int		ranking;
	t_stack	*tmp;
	t_stack	*tmp1;
	t_stack	*start;

	start = *stack;
	tmp1 = start;
	while (tmp1)
	{
		tmp = start;
		ranking = 0;
		while (tmp)
		{
			if (tmp1->data > tmp->data)
				ranking++;
			tmp = tmp->next;
		}
		tmp1->rank = ranking;
		tmp1 = tmp1->next;
	}
}
