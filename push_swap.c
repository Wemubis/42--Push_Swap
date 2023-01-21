/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:48 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/21 19:03:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_pile *a, t_pile *b)
{
	if (check_if_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
}
	// if (a->size <= 100)
	// 	sort_big(stack);
	// if (a->size <= 500)
	// 	sort_huge(stack);
