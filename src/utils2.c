/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:10:10 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 19:58:24 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_minor(t_node *node)
{
	int	index;
	int	min;
	int	index_min;
	t_node	*new_node;

	if (!node)
		return (0);
	min = node->content;
	index = 0;
	index_min = 0;
	new_node = node;
	while (new_node)
	{
		if (new_node->content < min)
		{
			min = new_node->content;
			index_min = index;
		}
		new_node = new_node->next;
		index++;
	}
	return (index_min);
}
