/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args_quoted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:34:43 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/10 14:03:57 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_freestr(char **str)
{
	char	*temp;

	if (!str)
		return ;
	while (*str)
	{
		temp = *str;
		str++;
		free(temp);
	}
	*str = NULL;
}

t_stack	*ft_parse_args_quoted(char **argv)
{
	t_stack	*stack;
	char	**temp;

	stack = NULL;
	temp = ft_split(argv[1], ' ');
	list_args(temp, &stack);
	ft_freestr(temp);
	free(temp);
	return (stack);
}
