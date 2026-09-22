/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaidation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-dieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:14:01 by nde-dieg          #+#    #+#             */
/*   Updated: 2026/09/22 15:39:13 by nde-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h>

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	str_to_long(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	fits_in_int(long value)
{
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicate(long *values, int count)
{
	int	i; //indices
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	long	value[argc];

	i = 0;
	while (i + 1 < argc)
	{
		if (is_number(argv[i + 1]) == 0)
		{
			printf("%s -> Error (no es un numero)\n", argv[i + 1]);
			return (1);
		}
		value[i] = str_to_long(argv[i + 1]);
		if (fits_in_int(value[i]) == 0)
		{
			printf("%s -> Error (no cabe en un int)\n", argv[i + 1]);
			return (1);
		}
		if (has_duplicate(value, i + 1) == 1)
		{
			printf("%s -> Error (duplicado)\n", argv[i + 1]);
			return (1);
		}
		printf("%s -> valido\n", argv[i + 1]);
		i++;
	}
	return (0);
}
