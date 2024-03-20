/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:16:31 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 21:16:31 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		ft_rra(stack_a, 1);
	else if (line[2] == 'b')
		ft_rrb(stack_b, 1);
	else if (line[2] == 'r')
		ft_rrr(stack_a, stack_b, 1);
	else
		return ;
}

void	*ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(stack_a, stack_b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(stack_a, stack_b, 1);
	else
		checker_error();
	return (get_next_line(0));
}

void ft_checker_sub(t_stack **stack_a, t_stack **stack_b, char *string)
{
	char *temp;

	while (*string != '\n' && string)
	{
		temp = string;
		string = ft_check(stack_a, stack_b, string);
		free(temp);
	}
	if (!ft_checksorted(*stack_a) || *stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(string);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char *string;

	stack_a = ft_process(argc, argv);
	stack_b = NULL;
	if (!stack_a || !ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		checker_error();
	}
	string = get_next_line(0);
	if (!ft_checksorted(stack_a) && !string)
		write(1, "KO\n", 3);
	else if (ft_checksorted(stack_a) && !string)
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&stack_a, &stack_b, string);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}