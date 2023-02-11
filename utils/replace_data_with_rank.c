/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_data_with_rank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:46:21 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/07 18:54:22 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_rank(char **av, char *arg, int k)
{
	int		i;
	int		rank;

	i = 0;
	rank = 0;
	while (i < k)
	{
		if (ft_atoi(arg) > ft_atoi(av[i]))
			rank++;
		i++;
	}
	return (rank);
}

int	*replace_data_with_rank(char **av)
{
	int		*tab_rank;
	int		i;
	int		k;

	k = 0;
	while (av[k])
		k++;
	tab_rank = malloc(sizeof(int *) * k);
	if (!tab_rank)
		error();
	i = 0;
	while (i < k)
	{
		tab_rank[i] = find_rank(av, av[i], k);
		i++;
	}
	return (tab_rank);
}
