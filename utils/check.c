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

int	check_if_sorted(t_pile *a)
{
	int		i;

	i = -1;
	while (++i < a->size)
	{
		if (a->first->data > a->first->next->data)
			return (0);
		a->first = a->first->next;
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
