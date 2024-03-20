/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu < sprodatu@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:25:39 by sprodatu          #+#    #+#             */
/*   Updated: 2024/03/20 21:25:39 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_Swap.h"

void	checker_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
