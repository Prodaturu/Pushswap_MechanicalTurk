/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:14:11 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/16 03:31:06 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rarb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->num, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rarb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->num))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->num, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->num != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
}
