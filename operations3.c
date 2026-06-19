/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:57:01 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/07 13:32:21 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_printf("pb\n");
}
