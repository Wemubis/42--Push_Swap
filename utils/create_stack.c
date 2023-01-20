/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 14:53:39 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	**split_arg_to_stack(t_stack **a, char *arg)
{
	t_stack	*top;
	char	**tab;
	int		tab_v2;
	int		x;

	tab = ft_split(arg, ' ');
	check_stack_validity(tab);
	x = 0;
	while (tab[x])
		x++;
	x--;
	while (x >= 0)
	{
		tab_v2 = ft_atoi(tab[x]);
		top = new_element(tab_v2);
		printf("%d-", top->data);
		push_stack(a, top->data);
		x--;
	}
	return (a);
}

t_stack	**fill_stack(t_stack **a, int ac, char **av)
{
	t_stack	*top;
	int		val;

	check_stack_validity(av);
	while (ac > 1)
	{
		val = ft_atoi(av[ac -1]);
		top = new_element(val);
		push_stack(a, top->data);
		ac--;
	}
	return (a);
}
