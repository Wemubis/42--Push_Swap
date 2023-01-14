/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:30 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/14 17:42:36 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;
	t_stack	*top;
	t_stack	*bottom;

	if (ac < 2)
		errors_process("e.g.: ./pushswap [nb] [nb] [nb]...");
	if (ac == 2)
		a = split_arg_to_stack(av[1]);
	if (ac > 2)
		a = fill_stack(ac, av);
	push_swap(a, b, top, bottom);
	exit(EXIT_SUCCESS);
}
