/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:31:45 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/03 19:14:59 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_len_stack(char **mtx)
{
	int	i;

	i = -1;
	while(mtx[++i])
		;
	return (i);
}

void	fill_stack(t_stack *stack, char **mtx)
{
	int	i;

	i = -1;
	while(mtx[++i])
	{
		if (!check_char(mtx[i]) || (ft_atoi(mtx[i]) < MIN_INT
			|| ft_atoi(mtx[i]) > MAX_INT))
		{
			free(stack->stack_a);
			free(stack->stack_b);
			ft_error();
		}
		stack->stack_a[i] = ft_atoi(mtx[i]);
	}
}
