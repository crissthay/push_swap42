/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:44:04 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 20:49:56 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_node **a, char **av)
{
	int		i;
	long	n;
	t_node	*new_node;

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
		new_node = node_new((int)n);
		node_add_back(a, new_node);
		i++;
	}
}

void	sort_stack(t_node **a)
{
	t_node	*b;
	int		size;

	b = NULL;
	size = tf_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sortingthree(a);
	else if (size == 4)
		sortingfour(a, &b);
	else if (size == 5)
		sortingfive(a, &b);
}

int	main(int ac, char **av)
{
	t_node	*a;

	a = NULL;
	if (ac < 2)
		return (0);
	parse_args(&a, av);
	if (!is_sorted(a))
	{
		index_node(a);
        sort_stack(&a);
	}
	free_all(a);
	return (0);
}
