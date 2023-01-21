/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:50:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 14:00:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack **stack)
{
	int		content;
	int		i;
	t_stack	*tmp;

	i = 0;
	content = (*stack)->data;
	if (!(*stack)->next)
		return (1);
	tmp = (*stack)->next;
	while ((content < tmp->data) && tmp->next)
	{
		content = tmp->data;
		tmp = tmp->next;
		i++;
	}
	if (i == size_stack(stack))
		return (1);
	return (0);
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

int	find_location(t_stack **stack, int rank)
{
	int	location;
	t_stack	*tmp;

	location = 0;
	tmp = *stack;
	while (tmp->rank != rank)
	{
		tmp = tmp->next;
		location++;
	}
	return (location);
}
