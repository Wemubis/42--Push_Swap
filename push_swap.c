/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:48 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/22 17:14:12 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pile *a, t_pile *b)
{
	if (check_if_sorted(a->head, a->size))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
}
	// if (a->size < 100)
	// 	sort_big(stack);
	// if (a->size < 500)
	// 	sort_huge(stack);
