/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:00:41 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:59 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingthree(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second > third)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (second > third && second > first)
	{
		rra(a);
		sa(a);
	}
	else if (second < first && second < third)
		sa(a);
	else if (third < first && third < second)
		rra(a);
}

void	sortingfour(t_node **a, t_node **b)
{
	int	min;

	if (!a || !*a)
		return ;
	min = sort_minor(*a);
	if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
		rra(a);
	pb(a, b);
	sortingthree(a);
	pa(a, b);
}

void	sortingfive(t_node **a, t_node **b)
{
	int	min;

	if (!a || !*a)
		return ;
	min = sort_minor(*a);
	if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min == 4)
		rra(a);
	pb(a, b);
	sortingthree(a);
	pa(a, b);
}
