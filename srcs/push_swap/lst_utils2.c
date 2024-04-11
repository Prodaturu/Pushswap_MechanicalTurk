/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:33:24 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/07 07:50:29 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_index(t_stack *a, int num)
{
	int		i;

	i = 0;
	while (a->num != num)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	ft_find_place_b(t_stack *stack_b, int num_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num_push > stack_b->num && num_push < ft_lstlast(stack_b)->num)
		i = 0;
	else if (num_push > ft_max(stack_b) || num_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->num < num_push || tmp->num > num_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *stack_a, int num_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num_push < stack_a->num && num_push > ft_lstlast(stack_a)->num)
		i = 0;
	else if (num_push > ft_max(stack_a) || num_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->num > num_push || tmp->num < num_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
