/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:48:58 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/12 15:24:18 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "Superlibft/Includes/libft.h"
# include "Superlibft/Includes/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;
}	t_stack;

// operations sur les piles
void	push(t_stack *dest, t_stack *src);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// operations sur les piles
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

// atol
long	ft_atol(const char *str);

// gestion des erreurs
int		check_errors(int ac, char **av);

// gestion des piles
t_stack	*create_stack(void);
t_list	*lst1_new(int content);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *stack);
void	push_node(t_stack *stack, t_list *node);

// algo petit
int		find_min_pos(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

// algo grand
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

// sorting algorithm
void	sort_small(t_stack *a, t_stack *b);
void	sorting_algorithm(t_stack *a, t_stack *b);

// convertit en les nombres en index
void	assign_index(t_stack *stack);

#endif
