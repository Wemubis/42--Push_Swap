/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_data_with_rank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:46:21 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 19:51:18 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_data_with_rank(t_pile *a)
{
	int		rank;
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp1 = a->first;
	while (tmp1)
	{
		tmp = a->first;
		rank = 0;
		while (tmp)
		{
			if (tmp1->data > tmp->data)
				rank++;
			tmp = tmp->next;
		}
		tmp1->data = rank;
		tmp1 = tmp1->next;
	}
}
