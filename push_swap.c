/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:58:11 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/18 18:49:51 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack 	*stack;
	t_topush	topush;
	int i;
	int	len;
	int j;
	int i_topa;
	
	len = 0;
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
	ft_check_doubles(stack);
	len += ft_sorting(stack);
	while (++i < stack->current_b)
	j = stack->current_a;
	i = -1;
	while (++i < j - 3)
	{
		topush = ft_count_moves(stack);
		ft_realsort(stack, topush);
	}
	ft_find_maxmin_a(stack);
	ft_sorting_a(stack);
	i = stack->current_b;
	j = -1;
	while (++j < i)
		ft_pushing_to_a(stack);
	final_sorting(stack);
	ft_close(stack);
}
