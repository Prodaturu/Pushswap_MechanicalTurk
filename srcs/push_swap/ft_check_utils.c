/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:57:30 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 00:57:30 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int digit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int	space(int character)
{
	if (character == ' ')
		return (1);
	return (0);
}

int	sign(int character)
{
	if (character != '-' && character != '+')
		return (0);
	return (1);
}

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
