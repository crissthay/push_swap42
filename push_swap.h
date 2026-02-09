/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontezu <tmontezu <tmontezu@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:49:03 by tmontezu          #+#    #+#             */
/*   Updated: 2026/02/09 00:27:23 by tmontezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "src/libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>


typedef struct s_node
{	
	void			*content;
	struct s_node	*next;
}	t_node;

// op
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rr(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rera(t_node **a);
void				rerb(t_node **b);
void				rerr(t_node **a, t_node **b);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

// error
long	ft_atol(const char *nptr);
int		is_digit_char(char *str);
int		hasdup(t_node *a, int n);
void 	error(void);
int 	is_sorted(t_node *a);
void 	free_all(t_node *a);
void	ft_index(t_node *a);
t_node	*node_new(int *value);
void    node_add_back(t_node **a, t_node *new);



#endif
