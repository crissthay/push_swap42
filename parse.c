/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:44:04 by tmontezu          #+#    #+#             */
/*   Updated: 2026/01/13 20:59:08 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_list **a, char **av)
{
	int		i;
	long	n;

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
		ft_lstadd_back(a, ft_lstnew((int)n));
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
