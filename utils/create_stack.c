/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/15 18:27:28 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*split_arg_to_stack(t_stack *a, char *arg)
{
	t_stack	*top;
	char	**tab;
	int		x;

	tab = ft_split(arg, ' ');
	check_stack_validity(tab);
	x = 0;
	while (tab[x])
		x++;
	while (x >= 0)
	{
		top = new_element((int)tab[x]);
		push_stack(a, top);
		x--;
	}
	return (a);
}

t_stack	*fill_stack(t_stack *a, int ac, char **av)
{
	t_stack	*top;

	check_stack_validity(av);
	while (ac > 0)
	{
		top = new_element((int)av[ac -1]);
		push_stack(a, top);
		ac--;
	}
	return (a);
}
