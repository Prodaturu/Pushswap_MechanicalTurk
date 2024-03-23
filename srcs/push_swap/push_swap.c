/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:33:11 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/23 23:54:26 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_process(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	else if (!ft_checksorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
