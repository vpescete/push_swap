/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:36 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 19:42:29 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	ft_error_prev(t_stack	*stack)
{
	ft_printf("Error\n");
	free(stack);
	exit(0);
}

void	ft_error(t_stack	*stack)
{
	ft_printf("Error\n");
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}
