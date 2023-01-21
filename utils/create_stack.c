/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 18:32:28 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_arg_to_stack(t_pile *a, char *arg)
{
	char	**tab;
	int		x;

	tab = ft_split(arg, ' ');
	check_stack_validity(tab);
	x = 0;
	while (tab[x])
		x++;
	a->size = x;
	x--;
	while (x >= 0)
	{
		push_before(a->first, new_element(ft_atoi(tab[x])));
		x--;
	}
}

void	fill_stack(t_pile *a, int ac, char **av)
{
	check_stack_validity(av);
	a->size = ac - 1;
	while (ac > 1)
	{
		push_after(a->first, new_element(ft_atoi(av[ac -1])));
		ac--;
	}
}
