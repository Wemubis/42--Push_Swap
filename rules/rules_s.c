/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:12:11 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/17 14:16:17 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *a, int bool)
{
	int	tmp;

	if (a->size <= 1)
		return ;
	tmp = a->head->next->data;
	a->head->next->data = a->head->data;
	a->head->data = tmp;
	if (bool == 0)
		write(1, "sa\n", 3);
}

void	sb(t_pile *b, int bool)
{
	int	tmp;

	if (b->size <= 1)
		return ;
	tmp = b->head->next->data;
	b->head->next->data = b->head->data;
	b->head->data = tmp;
	if (bool == 0)
		write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}
