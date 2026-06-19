/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:40:29 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/07 14:51:35 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}

void	sorting_algorithm(t_stack *a, t_stack *b)
{	
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}
