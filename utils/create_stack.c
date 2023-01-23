/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 18:31:31 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_arg_to_stack(t_pile *a, t_pile *b, char *arg)
{
	char	**tab;
	int		x;

	tab = ft_split(arg, ' ');
	check_stack_validity(tab);
	x = 0;
	while (tab[x])
		x++;
	a->size = x;
	a->head = new_element(ft_atoi(tab[x - 1]));
	b->size = 0;
	b->head = NULL;
	while (x)
	{
		push_before(a->head, new_element(ft_atoi(tab[x - 1])));
		a->head = a->head->prev;
		x--;
	}
}

void	fill_stack(t_pile *a, t_pile *b, int ac, char **av)
{
	check_stack_validity(av);
	a->size = ac;
	a->head = new_element(ft_atoi(av[ac - 1]));
	b->size = 0;
	b->head = NULL;
	ac--;
	while (ac)
	{
		push_before(a->head, new_element(ft_atoi(av[ac - 1])));
		a->head = a->head->prev;
		ac--;
	}
}
