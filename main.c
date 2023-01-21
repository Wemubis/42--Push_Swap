/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:30 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 18:32:54 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	stack_a;
	t_pile	stack_b;

	if (ac < 2)
		errors_process("e.g.: ./pushswap [nb] [nb] [nb]...");
	if (ac == 2)
		split_arg_to_stack(&stack_a, av[1]);
	if (ac > 2)
		fill_stack(&stack_a, ac, av);
	push_swap(&stack_a, &stack_b);
	clear_stack(stack_a);
	return (0);
}
