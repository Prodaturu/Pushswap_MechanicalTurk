/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:06:31 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 01:06:31 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	list_args(char **argv, t_stack **stack)
{
	long long	index;

	index = 1;
	while (argv[index])
	{
		ft_add_back(stack, ft_stack_new(ft_atoi(argv[index])));
		index++;
	}
}
