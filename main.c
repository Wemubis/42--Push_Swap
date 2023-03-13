/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:30:30 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/13 13:29:05 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;

	if (ac < 2 || (!ft_isdigit(av[1][0]) && av[1][0] != '-'))
		return (0);
	if (ac == 2)
		split_arg_to_stack(&a, &b, av[1]);
	if (ac > 2)
		fill_stack(&a, &b, ac - 1, av + 1);
	push_swap(&a, &b);
	free_stack(a.head, a.size);
	return (0);
}
