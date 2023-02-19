/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:37:25 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/19 12:39:45 by vpescete         ###   ########.fr       */
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
