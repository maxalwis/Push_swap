/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:10:26 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/07 14:54:46 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_list	*current;
	int		min;
	int		min_pos;
	int		current_pos;

	current = a->top;
	min = current->content;
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

void	sort_2(t_stack *a)
{
	if (a->top->content > a->top->next->content)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->content;
	mid = a->top->next->content;
	bot = a->top->next->next->content;
	if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > bot && bot > mid)
		ra(a);
	else if (mid > top && top > bot)
		rra(a);
	else if (mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && bot > top)
		sa(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	while (min_pos > 0)
	{
		ra(a);
		min_pos--;
	}
	pb(b, a);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	while (min_pos > 0)
	{
		ra(a);
		min_pos--;
	}
	pb(b, a);
	min_pos = find_min_pos(a);
	while (min_pos > 0)
	{
		ra(a);
		min_pos--;
	}
	pb(b, a);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
