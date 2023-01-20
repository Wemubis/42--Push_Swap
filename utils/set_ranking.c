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
	int		i;
	int		k;
	t_stack	*temp;
	t_stack	*start;

	i = 0;
	start = stack[0];
	k = -1;
	while (stack[++k])
	{
		temp = start;
		ranking = 0;
		while (temp)
		{
			if (stack[k]->data > temp->data)
				ranking++;
			temp = temp->next;
		}
		stack[k]->rank = ranking;
		stack[k] = stack[k]->next;
		i++;
	}
}
