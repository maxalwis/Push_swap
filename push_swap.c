/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:37:35 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/10 18:46:49 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack *a, char **args, int start)
{
	int		i;
	t_list	*node;

	i = start;
	while (args[i])
	{
		node = lst1_new(ft_atoi(args[i]));
		if (!node)
		{
			free_stack(a);
			exit(1);
		}
		push_node(a, node);
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	process_args(int ac, char **av, t_stack *a)
{
	char	**args;
	int		num;

	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			return (free_split(args), 1);
		num = count_args(args);
		if (check_errors(num, args))
			return (free_split(args), ft_printf("Error\n"), 1);
		init_stack_a(a, args, 0);
		return (free_split(args), 0);
	}
	if (check_errors(ac - 1, av + 1))
		return (ft_printf("Error\n"), 1);
	init_stack_a(a, av, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		process;

	a = create_stack();
	b = create_stack();
	if (!a || !b)
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	process = process_args(ac, av, a);
	if (process)
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	assign_index(a);
	sorting_algorithm(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
