/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:09:50 by tmontezu          #+#    #+#             */
/*   Updated: 2026/01/13 20:50:25 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rr(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

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

void	rra(t_list **a)
{
	rr(a);
	write(1, "rra\n", 3);
}

void	rrb(t_list **b)
{
	rr(b);
	write(1, "rrb\n", 3);
}

void	rrr(t_list **a, t_list **b)
{
	rr(a);
	rr(b);
	write(1, "rrr\n", 3);
}
