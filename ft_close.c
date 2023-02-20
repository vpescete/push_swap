/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:37:25 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 12:51:10 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}

void	ft_close_init(t_stack *stack)
{
	free(stack);
	exit(0);
}
