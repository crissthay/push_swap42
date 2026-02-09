/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:50:06 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 21:03:19 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_node(t_node *a)
{
	t_node	*temp1;
	t_node	*temp2;
	int		count;

	temp1 = a;
	while (temp1)
	{
		count = 0;
		temp2 = a;
		while (temp2)
		{
			if (temp2->content < temp1->content)
				count++;
			temp2 = temp2->next;
		}
		temp1->content = count;
		temp1 = temp1->next;
	}
}

void	free_all(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

t_node *node_new(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->content = value;
    node->next = NULL;
    return (node);
}

void	node_add_back(t_node **a, t_node *new)
{
	t_node	*tmp;

	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	tf_lstsize(t_node *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	printf("len: %d\n", len);
	return (len);
}
