/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:49:03 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/10 19:21:11 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}					t_node;

// op
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rr(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

// error
long				ft_atol(const char *nptr);
int					is_digit_char(char *str);
int					is_sorted(t_node *a);
int					hasdup(t_node *a, int n);
void				error(t_node *a);

// parse
void				parse_args(t_node **a, char **av);
void				sort_stack(t_node **a);

// sortfive=
void				sortingthree(t_node **a);
void				sortingfour(t_node **a, t_node **b);
void				sortingfive(t_node **a, t_node **b);

// utils
void				index_node(t_node *a);
void				free_all(t_node *a);
void				node_add_back(t_node **a, t_node *new);
int					tf_lstsize(t_node *lst);
t_node				*node_new(int value);

// ultils2
int					sort_minor(t_node *node);
void				free_split(char **split);
void				free_list(char **nums, t_node **a);

// sort
void				radix_sort(t_node **a, t_node **b);
int					bits_nedded(int b);

#endif
