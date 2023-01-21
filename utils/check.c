/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:50:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 20:21:59 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_if_sorted(t_pile *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a->first;
	while (++i < a->size)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_stack_validity(char **args)
{
	int		i;
	int		j;
	int		after_atoi;

	i = 1;
	while (args[i])
	{
		after_atoi = ft_atoi(args[i]);
		j = i;
		while (args[j])
		{
			if (args[i] == args[j + 1])
				errors_process("A double has been detected");
			j++;
		}
		i++;
	}
}

int	find_location(t_stack *top, int rank)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = top;
	while (tmp->data != rank)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
