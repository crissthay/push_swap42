/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:04:58 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/10 19:24:00 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits_nedded(int b)
{
	int	bits;

	bits = 0;
	while (b)
	{
		b = b >> 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	bit;
	int	i;

	bit = 0;
	size = tf_lstsize(*a);
	while (bit < bits_nedded(size - 1))
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
