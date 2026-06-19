/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:57:15 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/10 18:46:33 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;

	current = a->top;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*lst1_new(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	push_node(t_stack *stack, t_list *node)
{
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}
