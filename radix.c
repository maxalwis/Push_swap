/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:26 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/12 12:02:57 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int		max_num;
	int		max_bits;
	t_list	*current;

	max_num = INT_MIN;
	max_bits = 0;
	current = stack->top;
	while (current)
	{
		if (current->index > max_num)
			max_num = current->index;
		current = current->next;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;
	t_list	*current;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			current = a->top;
			if (((current->index >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

void	assign_index(t_stack *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	if (stack == NULL || stack->top == NULL)
		return ;
	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->content < current->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
