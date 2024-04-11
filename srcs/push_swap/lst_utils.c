/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:28:36 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/07 07:50:08 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	size_t	kolatha;

	kolatha = 0;
	while (lst)
	{
		lst = lst->next;
		kolatha++;
	}
	return (kolatha);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}
