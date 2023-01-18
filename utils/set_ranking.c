/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ranking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:55:25 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 15:31:44 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ranking(t_stack *stack)
{
	int		ranking;
	int		i;
	t_stack	*temp;
	t_stack	*start;

	i = 0;
	start = stack;
	while (stack)
	{
		temp = start;
		ranking = 0;
		while (temp)
		{
			if (stack->data > temp->data)
				ranking++;
			temp = temp->next;
		}
		stack->rank = ranking;
		stack = stack->next;
		i++;
	}
}
