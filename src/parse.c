/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu <tmontezu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:44:04 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 00:21:43 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_args(t_node **a, char **av)
{
    int i;
    long n;
    int *value;
    t_node *new_node;

    i = 1;
    while (av[i])
    {
        if (!is_digit_char(av[i]))
            error();
        n = ft_atol(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            error();
        if (hasdup(*a, (int)n))
            error();
        value = malloc(sizeof(int));
        if (!value)
            error();
        *value = (int)n;
        new_node = node_new(value);
        node_add_back(a, new_node);
        i++;
    }
}

int main(int ac, char **av)
{
    t_node *a = NULL;

    if (ac < 2)
        return 0;

    parse_args(&a, av);
    if (!is_sorted(a))
    {
        ft_index(a);
         // radix
    }

    free_all(a);
    return 0;
}

