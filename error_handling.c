/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:12:05 by maalwis           #+#    #+#             */
/*   Updated: 2025/03/10 18:39:10 by maalwis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || !str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_limit(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (num != ft_atol(str))
		return (0);
	return (1);
}

int	check_double(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int ac, char **av)
{
	int		i;
	int		*numbers;

	if (ac < 1)
		return (1);
	numbers = malloc(sizeof(int) * ac);
	if (!numbers)
		return (1);
	i = 0;
	while (i < ac)
	{
		if (!check_number(av[i]) || !check_limit(av[i]))
			return (free(numbers), 1);
		numbers[i] = ft_atoi(av[i]);
		i++;
	}
	if (check_double(numbers, ac))
		return (free(numbers), 1);
	free(numbers);
	return (0);
}
