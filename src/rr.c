/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:09:50 by tmontezu          #+#    #+#             */
/*   Updated: 2026/01/15 15:37:40 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rer(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rera(t_node **a)
{
	rer(a);
	write(1, "rra\n", 3);
}

void	rerb(t_node **b)
{
	rer(b);
	write(1, "rrb\n", 3);
}

void	rerr(t_node **a, t_node **b)
{
	rer(a);
	rer(b);
	write(1, "rrr\n", 3);
}
