/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:53:46 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 00:53:46 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_sorted(t_stack *stack)
{
	int value;

	value = stack->num;
	while (stack)
	{
		if (stack->num < value)
			return (0);
		value = stack->num;
		stack = stack->next;
	}
	return (1);
}