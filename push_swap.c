/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:48 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/03 23:51:44 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pile *a, t_pile *b)
{
	if (check_if_sorted(a->head, a->size))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
	 	sort_big(a, b);
}