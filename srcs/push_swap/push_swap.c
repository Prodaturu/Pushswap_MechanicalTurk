/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:33:11 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/13 14:53:07 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// check if there is any type of below error and return 0 if there is 1 if not
	// Check if the string is empty
	// Skip leading whitespace
	// Check for optional sign
	// The string is not a number if it doesn't start with a digit
	// Convert the string to a long integer
	// Check for conversion errors
	// The string is a valid number

int	is_space(unsigned char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_valid_number(char *str)
{
	long	val;
	int		errno;

	if (str == NULL || *str == '\0')
		return (0);
	while (is_space((unsigned char)*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit((unsigned char)*str))
		return (0);
	val = ft_atoi2(str);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	return (1);
}

// go through each string and check if it is ok
int	validate_args(int argc, char **argv)
{
	int	index;

	if (argc < 2)
		return (-1);
	index = 1;
	while (index < argc)
	{
		if (!is_valid_number(argv[index]))
			return (-1);
		index++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	if (validate_args(argc, argv) == -1)
		return (ft_error(), 0);
	stack_a = ft_process(argc, argv);
	if (!*argv[1] || !stack_a || ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	else if (!ft_checksorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
