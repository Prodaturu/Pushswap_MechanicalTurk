/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:01:15 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/19 23:01:15 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_atoi2(const char *str)
{
	int				sign;
	long long int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error();
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * sign;
	if (res > 2147483647 || res < -2147483648)
		ft_error();
	return ((int)res);
}

t_stack	*ft_process2(char **argv)
{
	t_stack	*stack;
	char	**temp;
	int		i;
	int		j;

	stack = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		j = ft_atoi2(temp[i]);
		ft_add_back(&stack, ft_stack_new(j));
		i++;
	}
	ft_freestr(temp);
	free(temp);
	return(stack);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*stack;
	int		index;
	int		j;

		index = 1;
	stack = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		stack = ft_process2(argv);
	else
	{
		while (index < argc)
		{
			j = ft_atoi2(argv[index]);
			ft_add_back(&stack, ft_stack_new(j));
			index++;
		}
	}
	return (stack);
}
