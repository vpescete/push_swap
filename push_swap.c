/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:58:11 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/14 19:25:46 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack;
	t_topush	topush;
	int i = 0;
	int	len;
	
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
	// while (i < stack->current_b)
	// {
	// 	printf(" main stack_b[%i]: %d\n", i, stack->stack_b[i]);
	// 	i++;
	// }
	// printf("moves: %d\n", len);
	pb(stack);
	// pb(stack);
	// pb(stack);
	// pb(stack);
	// pb(stack);
	// printf("max_b: %d -- min_b: %d\n", stack->max_b, stack->min_b);
	// while (i < stack->current_b)
	// {
	// 	printf(" main stack_b[%i]: %d\n", i, stack->stack_b[i]);
	// 	i++;
	// }
	topush = ft_count_moves(stack);
	
	// printf(" count_moves: %i\n index_a: %i\n index_b: %i\n", topush.count_moves, topush.index_a, topush.index_b);

	printf("						count_moves: %d\n", topush.count_moves);
	ft_close(stack);
}
