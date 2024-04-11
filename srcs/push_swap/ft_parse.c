/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:39:19 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/10 18:13:14 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		stack = ft_parse_args_quoted(argv);
	else
		list_args(argv, &stack);
	return (stack);
}
