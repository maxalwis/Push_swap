/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementations_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:21:05 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/05 14:35:12 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	t_list	*temp;

	if (src == NULL || src->top == NULL)
		return ;
	temp = src->top;
	src->top = src->top->next;
	if (!src->top)
		src->bottom = NULL;
	temp->next = dest->top;
	dest->top = temp;
	if (dest->bottom == NULL)
		dest->bottom = temp;
	src->size--;
	dest->size++;
}

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	second = stack->top->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	rotate(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	current = stack->top;
	stack->top = stack->top->next;
	current->next = NULL;
	stack->bottom->next = current;
	stack->bottom = current;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*current;
	t_list	*prev;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	current = stack->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	else
		stack->top = NULL;
	current->next = stack->top;
	stack->top = current;
	if (prev == NULL)
		stack->bottom = current;
	else
		stack->bottom = prev;
}
