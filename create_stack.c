/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/14 17:20:08 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**split_arg_to_stack(char *arg)
{
	t_stack	**a;
	t_stack	*top;
	char	**tab;
	int		x;

	tab = ft_split(arg, ' ');
	x = 0;
	while (tab[x])
		x++;
	while (x >= 0)
	{
		top = new_element_stack((int)tab[x]);
		if (ft_isdigit((int)tab[x]))
			errors_process("A non digit argument has been detected");
		add_stack(a, top);
		x--;
	}
	return (a);
}

t_stack	**fill_stack(int ac, char **av)
{
	t_stack	**a;
	t_stack	*top;

	while (ac > 0)
	{
		top = new_element_stack((int)av[ac -1]);
		if (ft_isdigit((int)av[ac]))
			errors_process("A non digit argument has been detected");
		add_stack(a, top);
		ac--;
	}
	return (a);
}
