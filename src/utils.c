/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu <tmontezu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:50:06 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 00:20:46 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index(t_node *a)
{
    t_node *temp1 = a;
    t_node *temp2;
    int count;
    while(temp1)
    {
        count = 0;
        temp2 = a;
        while (temp2)
        {
                if(*(int *)temp2->content < *(int *)temp1->content)
                    count++;
                temp2 = temp2->next;
        }
        *(int *)temp1->content = count;
        temp1 = temp1->next;
    }  
}

void free_all(t_node *a)
{
    t_node *tmp;
    while (a)
    {
        tmp = a->next;
        free(a->content); 
        free(a);        
        a = tmp;
    }
}
t_node *node_new(int *value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->content = value;
    node->next = NULL;
    return (node);
}
void node_add_back(t_node **a, t_node *new)
{
    t_node *tmp;

    if (!*a)
    {
        *a = new;
        return;
    }
    tmp = *a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}


