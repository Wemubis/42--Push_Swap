/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:29:46 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/08 00:14:18 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median(t_pile *stack)
{
	return (stack->size / 2);
}

int	data_min(t_pile *stack)
{
	int		i;
	int		data_min;
	t_stack	*tmp;

	i = 0;
	tmp = stack->head;
	data_min = tmp->data;
	while (i < stack->size)
	{
		if (data_min > tmp->next->data)
			data_min = tmp->next->data;
		tmp = tmp->next;
		i++;
	}
	return (data_min);
}

int	data_max(t_pile *stack)
{
	int		i;
	int		data_max;
	t_stack	*tmp;

	i = 0;
	tmp = stack->head;
	data_max = tmp->data;
	while (i < stack->size)
	{
		if (data_max < tmp->next->data)
			data_max = tmp->next->data;
		tmp = tmp->next;
		i++;
	}
	return (data_max);
}

int	location(t_pile *stack, int rank)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = stack->head;
	while (tmp->data != rank)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	theorical_positioning(t_pile *a, int data)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	if (!a->head)
		return (0);
	tmp = a->head;
	while (data > tmp->data && tmp->next->data != data_max(a))
	{
		tmp = tmp->next;
		index++;
	}
	if (index > 0)
		return (index);
	while (data < tmp->data && tmp->prev->data != data_max(a))
	{
		tmp = tmp->prev;
		index--;
	}
	return (index);
}