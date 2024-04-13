/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:01:15 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/13 14:35:41 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi2(const char *str)
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

t_stack	*ft_process_arg(char *arg, t_stack	*stack)
{
	char	**temp;
	int		i;
	int		index2;

	if (ft_strchr(arg, ' '))
	{
		i = 0;
		temp = ft_split(arg, ' ');
		while (temp[i])
		{
			if ((*temp[i] == '-' || *temp[i] == '+') && !ft_isdigit(temp[i][1]))
				ft_error();
			index2 = ft_atoi2(temp[i]);
			ft_add_back(&stack, ft_stack_new(index2));
			i++;
		}
		return (ft_freestr(temp), free(temp), stack);
	}
	else
	{
		if ((*arg == '-' || *arg == '+') && !ft_isdigit(arg[1]))
			ft_error();
		i = ft_atoi2(arg);
		return (ft_add_back(&stack, ft_stack_new(i)), stack);
	}
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*stack;
	int		index;

	index = 1;
	stack = NULL;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		stack = ft_process_arg(argv[index], stack);
		index++;
	}
	return (stack);
}

// t_stack	*ft_process(int argc, char **argv)
// {
// 	t_stack	*stack;
// 	int		index;
// 	int		i;
// 	int		j;
// 	char	**temp;

// 	index = 1;
// 	stack = NULL;
// 	if (argc < 2)
// 		ft_error();
// 	while (index < argc)
// 	{
// 		if (ft_strchr(argv[index], ' '))
// 		{
// 			temp = ft_split(argv[index], ' ');
// 			i = 0;
// 			while (temp[i])
// 			{
// 				if ((*temp[i] == '-' || *temp[i] == '+') 
//					&& !ft_isdigit(temp[i][1]))
// 					ft_error();
// 				j = ft_atoi2(temp[i]);
// 				ft_add_back(&stack, ft_stack_new(j));
// 				i++;
// 			}
// 			ft_freestr(temp);
// 			free(temp);
// 		}
// 		else
// 		{
// 			if ((*argv[index] == '-' || *argv[index] == '+')
//				&& !ft_isdigit(argv[index][1]))
// 				ft_error();
// 			j = ft_atoi2(argv[index]);
// 			ft_add_back(&stack, ft_stack_new(j));
// 		}
// 		index++;
// 	}
// 	return (stack);
// }

// t_stack	*ft_process2(char **argv, int index)
// {
// 	t_stack	*stack;
// 	char	**temp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	temp = ft_split(argv[index], ' ');
// 	while (temp[i])
// 	{
// 		if ((*temp[i] == '-' || *temp[i] == '+') && !ft_isdigit(temp[i][1]))
// 			ft_error();
// 		j = ft_atoi2(temp[i]);
// 		ft_add_back(&stack, ft_stack_new(j));
// 		i++;
// 	}
// 	ft_freestr(temp);
// 	free(temp);
// 	return (stack);
// }

// t_stack	*ft_process(int argc, char **argv)
// {
// 	t_stack	*stack;
// 	int		index;
// 	int		j;

// 	index = 1;
// 	stack = NULL;
// 	if (argc < 2)
// 		ft_error();
// 	if (argc == 2)
// 		stack = ft_process2(argv, 1);
// 	else
// 	{
// 		while (index < argc)
// 		{
// 			if ((*argv[index] == '-' || *argv[index] == '+')
// 				&& (!ft_isdigit((argv[index][1]))))
// 				ft_error();
// 			if (ft_strchr(argv[index], ' '))
// 			{
// 				stack = ft_process2(argv, index);
// 				index++;
// 				continue;
// 			}
// 			j = ft_atoi2(argv[index]);
// 			ft_add_back(&stack, ft_stack_new(j));
// 			index++;
// 		}
// 	}
// 	return (stack);
// }
