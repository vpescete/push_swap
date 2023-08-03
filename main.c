/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:58:11 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/03 20:35:11 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index_b(t_stack *stack, int idx_a)
{
	int	i;

	i = -1;
	stack->tmp.idx_a = idx_a;
	stack->tmp.idx_b = 0;
	if (stack->stack_a[idx_a] > stack->stack_b[stack->index_maxb]
		|| stack->stack_a[idx_a] < stack->stack_b[stack->index_minb])
	{
		stack->tmp.idx_b = stack->index_maxb;
		return ;
	}
	while (++i < stack->len_b - 1)
	{
		if (stack->stack_a[idx_a] < stack->stack_b[i]
			&& stack->stack_a[idx_a] > stack->stack_b[i + 1])
		{
			stack->tmp.idx_b = i + 1;
			return ;
		}
	}
}

void	cheapest_num(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len_a)
	{
		find_index_b(stack, i);
		// find_cheapest_mv(stack ,i);
	}
}

void	sort(t_stack *stack)
{
	int	i;
	
	pb(stack, 1);
	pb(stack, 1);
	
	i = -1;
	// while (++i < stack->len_b)
	// 	printf("%d\n", stack->stack_b[i]);
	while (++i < stack->len_a - 3)
	{
		cheapest_num(stack);
		// execute_move(stack);
	}
}

void	three_sort(t_stack *stack)
{
	set_maxmin(stack);
	if (stack->index_maxa == 1 && stack->index_mina == 0)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (stack->index_maxa == 0 && stack->index_mina == 1)
		ra(stack, 1);
	else if (stack->index_maxa == 0 && stack->index_mina == 2)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (stack->index_maxa == 1 && stack->index_mina == 2)
		rra(stack, 1);
	else if (stack->index_maxa == 2 && stack->index_mina == 1)
		sa(stack, 1);
}

void	sorting(t_stack *stack)
{
	check_sorted(stack);
	if (stack->len_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa(stack, 1);
		ft_close(stack);
	}
	else if (stack->len_a == 3)
		three_sort(stack);
	else
		sort(stack);
}

int	main(int ac, char **av)
{
	t_stack		stack;

	if (ac > 1)
		get_input(av, ac, &stack);
	sorting(&stack);
	return (0);
}
