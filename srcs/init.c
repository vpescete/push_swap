/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:40:25 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/03 23:23:46 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_one(char *string, t_stack *stack)
{
	char	**mtx;
	int		i;

	mtx = ft_split(string, ' ');
	i = count_len_stack(mtx);
	stack->stack_a = ft_calloc(i, sizeof(int));
	stack->stack_b = ft_calloc(i, sizeof(int));
	stack->len_a = i;
	stack->len_b = 0;
	fill_stack(stack, mtx);
	free_mtx(mtx);
}

void	init_two(char **av, int ac, t_stack *stack)
{
	int	i;

	av++;
	stack->stack_a = ft_calloc(ac - 1, sizeof(int));
	stack->stack_b = ft_calloc(ac - 1, sizeof(int));
	stack->len_a = ac - 1;
	stack->len_b = 0;
	i = -1;
	while (++i < ac - 1)
	{
		if (!check_char(av[i]) || (ft_atoi(av[i]) < MIN_INT
			|| ft_atoi(av[i]) > MAX_INT))
		{
			free(stack->stack_a);
			free(stack->stack_b);
			ft_error();
		}
		stack->stack_a[i] = ft_atoi(av[i]);
	}
}

void	get_input(char **av, int ac, t_stack *stack)
{
	if (ac == 2)
		init_one(av[1], stack);
	else
		init_two(av, ac, stack);
	check_double(stack);
}