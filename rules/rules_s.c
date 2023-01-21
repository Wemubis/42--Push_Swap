/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:12:11 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 18:12:28 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *a)
{
	int	tmp;

	if (a->size <= 1)
		return ;
	tmp = a->first->next->data;
	a->first->next->data = a->first->data;
	a->first->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_pile *b)
{
	int	tmp;

	if (b->size <= 1)
		return ;
	tmp = b->first->next->data;
	b->first->next->data = b->first->data;
	b->first->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
