/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:14:06 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 14:44:33 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile stack)
{
	if (stack_is_empty(stack.b) == 1)
		return ;
	push_stack(stack.a, (*stack.b)->data);
	pop_stack(stack.b);
	write(1, "pa\n", 3);
}

void	pb(t_pile stack)
{
	if (stack_is_empty(stack.a) == 1)
		return ;
	push_stack(stack.b, (*stack.a)->data);
	pop_stack(stack.a);
	write(1, "pb\n", 3);
}
