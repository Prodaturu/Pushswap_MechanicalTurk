/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:47:07 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/07 08:51:12 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (!j)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (!j)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (!j)
		write(1, "rrr\n", 4);
}

// void	ft_rrr_sub(t_stack **b, int j)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = *b;
// 	while ((*b)->next)
// 	{
// 		i++;
// 		*b = (*b)->next;
// 	}
// 	(*b)->next = tmp;
// 	while (i > 1)
// 	{
// 		tmp = tmp->next;
// 		i--;
// 	}
// 	tmp->next = NULL;
// 	if (!j)
// 		write(1, "rrr\n", 4);
// }

// void	ft_rrr(t_stack **a, t_stack **b, int j)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	if (!*a || !((*a)->next) || !*b || !((*b)->next))
// 		return ;
// 	i = 0;
// 	tmp = *a;
// 	while ((*a)->next)
// 	{
// 		i++;
// 		*a = (*a)->next;
// 	}
// 	(*a)->next = tmp;
// 	while (i > 1)
// 	{
// 		tmp = tmp->next;
// 		i--;
// 	}
// 	tmp->next = NULL;
// 	ft_rrr_sub(b, j);
// }
