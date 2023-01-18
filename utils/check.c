/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:50:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/18 17:19:38 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *stack)
{
	int		temp_content;
	int		i;
	t_stack	*tmp;

	i = 0;
	temp_content = stack->data;
	tmp = stack->next;
	while ((temp_content < tmp->data) && tmp->next)
	{
		temp_content = tmp->data;
		tmp = stack->next;
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
	char	*after_itoa;
	char	**test_double;

	i = 0;
	test_double = args;
	while (args[++i])
	{
		after_atoi = atoi(args[i]);
		after_itoa = itoa(after_atoi);
		if (args[i] != after_itoa)
			errors_process("A non int has been detected");
		j = i;
		while (args[j])
		{
			if (args[i] == test_double[j])
				errors_process("A double has been detected");
			j++;
		}
	}
}

int	find_location(t_stack *stack, int rank)
{
	int	location;

	location = 0;
	while (stack->rank != rank)
	{
		stack = stack->next;
		location++;
	}
	return (location);
}
