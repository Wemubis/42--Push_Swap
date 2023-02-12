/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:50:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/12 14:14:01 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	is_number_int(int number, char *str)
{
	if (number == -1 && ft_strcmp("-1", str))
		error();
	if (*str == '-' && number < 0)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error();
		str++;
	}
}

int	check_if_sorted(t_pile *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack->head;
	while (i < (stack->size - 1))
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	check_stack_validity(char **args)
{
	int		i;
	int		j;

	i = 0;
	if (!args[i])
		exit(EXIT_FAILURE);
	while (args[i])
	{
		is_number_int(ft_atoi(args[i]), args[i]);
		j = i + 1;
		while (args[j])
		{
			if (!ft_strcmp(args[i], args[j]))
				error();
			j++;
		}
		i++;
	}
}
