/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:42:14 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 02:42:14 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->num != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->num != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->num != c)
			ft_rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->num != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->num != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->num != c)
			ft_rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->num != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->num != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
