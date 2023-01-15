/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_validity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:04:28 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 18:37:55 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_validity(char	**args)
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
