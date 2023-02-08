/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/07 19:05:04 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	split_arg_to_stack(t_pile *a, t_pile *b, char *arg)
{
	char	**tab;
	int		*tab_rank;
	int		x;

	tab = ft_split(arg, ' ');
	check_stack_validity(tab);
	tab_rank = replace_data_with_rank(tab);
	x = 0;
	while (tab[x])
		x++;
	a->size = x;
	a->head = new_element(tab_rank[x - 1]);
	b->size = 0;
	b->head = NULL;
	while (x)
	{
		push_before(a->head, new_element(tab_rank[x - 1]));
		a->head = a->head->prev;
		x--;
	}
	free_tab(tab);
	free(tab_rank);
}

void	fill_stack(t_pile *a, t_pile *b, int ac, char **av)
{
	int	*tab_rank;

	check_stack_validity(av);
	tab_rank = replace_data_with_rank(av);
	a->size = ac;
	a->head = new_element(tab_rank[ac - 1]);
	b->size = 0;
	b->head = NULL;
	ac--;
	while (ac)
	{
		push_before(a->head, new_element(tab_rank[ac - 1]));
		a->head = a->head->prev;
		ac--;
	}
	free(tab_rank);
}
