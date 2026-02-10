/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:44:04 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/10 19:21:46 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_numbers(t_node **a, char *str)
{
	char	**nums;
	int		j;
	t_node	*new_node;
	long	n;

	nums = ft_split(str, ' ');
	j = 0;
	if (!nums)
		error(*a);
	while (nums[j])
	{
		if (!is_digit_char(nums[j]))
			free_list(nums, a);
		n = ft_atol(nums[j]);
		if (n > INT_MAX || n < INT_MIN)
			free_list(nums, a);
		if (hasdup(*a, (int)n))
			free_list(nums, a);
		new_node = node_new((int)n);
		node_add_back(a, new_node);
		j++;
	}
	free_split(nums);
}

void	parse_args(t_node **a, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		process_numbers(a, av[i]);
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
	else
		radix_sort(a, &b);
}

static void	print_stack(t_node *head_a, t_node *head_b)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = head_a;
	node_b = head_b;
	while (node_a || node_b)
	{
		if (node_a)
		{
			printf("%d %d", node_a->content, node_a->index);
			node_a = node_a->next;
		}
		printf("\t");
		if (node_b)
		{
			printf("%d %d", node_b->content, node_b->index);
			node_b = node_b->next;
		}
		printf("\n");
	}
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
	print_stack(a, NULL);
	free_all(a);
	return (0);
}
