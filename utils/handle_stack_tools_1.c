/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack_tools_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:44:53 by mle-boud          #+#    #+#             */
/*   Updated: 2023/01/20 14:01:08 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		x;

	tmp = *stack;
	x = 0;
	while (tmp)
	{
		tmp = tmp->next;
		x++;
	}
	return (x);
}
