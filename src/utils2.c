/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:10:10 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/10 19:21:55 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_minor(t_node *node)
{
	int		index;
	int		min;
	int		index_min;
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

void	free_list(char **nums, t_node **a)
{
	free_split(nums);
	error(*a);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
