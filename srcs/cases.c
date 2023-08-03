/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:09:05 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 23:37:52 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_one(t_stack *stack)
{
	if (stack->tmp.idx_a >= stack->tmp.idx_b)
		stack->tmp.tmp_mv = stack->tmp.idx_a;
	else
		stack->tmp.tmp_mv = stack->tmp.idx_b;
}

void	case_two(t_stack *stack)
{
	if (stack->len_a - stack->tmp.idx_a >= stack->len_b - stack->tmp.idx_b)
		stack->tmp.tmp_mv = stack->len_a - stack->tmp.idx_a;
	else
		stack->tmp.tmp_mv = stack->len_b - stack->tmp.idx_b;
}
