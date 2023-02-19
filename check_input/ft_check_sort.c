/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:02:45 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/19 13:34:43 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_init(char **av, int ac, t_stack *stack)
{
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		stack = ft_check_stack(av[1], stack);
		ft_fill_stack(av[1], stack);
	}
	else
	{
		stack = ft_check_av(av, ac, stack);
		ft_fill_stack_2(av, ac, stack);
	}
	ft_check_init_sort(stack);
	ft_check_doubles(stack);
	return (stack);
}

void	ft_check_init_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return ;
		i++;
	}
	if (i == stack->current_a - 1)
		exit(0);
}
