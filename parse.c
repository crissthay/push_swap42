/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:44:04 by tmontezu          #+#    #+#             */
/*   Updated: 2026/01/15 15:23:50 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_list **a, char **av)
{
	int		i;
	long	n;
	int		*value;

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
		if(!value)
			error();
		*value = (int)n;
		t_list *new_node = ft_lstnew(value);
		ft_lstadd_back(a, new_node);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac < 2)
		return (0);
	parse_args(&a, av);
	return (0);
}
