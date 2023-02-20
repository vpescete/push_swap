/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:27:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/20 19:43:29 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../libs/get_next_line/get_next_line.h"

void	check_move(char *cmd, t_stack *stack)
{
	if (cmd[0] == 'p' && cmd[1] == 'a' && cmd[2] == '\n')
		pa(stack, 0);
	else if (cmd[0] == 'p' && cmd[1] == 'b' && cmd[2] == '\n')
		pb(stack, 0);
	else if (cmd[0] == 's' && cmd[1] == 'a' && cmd[2] == '\n')
		sa(stack, 0);
	else if (cmd[0] == 's' && cmd[1] == 'b' && cmd[2] == '\n')
		sb(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'a' && cmd[2] == '\n')
		ra(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'b' && cmd[2] == '\n')
		rb(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == '\n')
		rr(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a' && cmd[3] == '\n')
		rra(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b' && cmd[3] == '\n')
		rrb(stack, 0);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r' && cmd[3] == '\n')
		rrr(stack, 0);
	else
		ft_error(stack);
}

int	ft_check_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*stack;
	char		*cmd;
	int			final;

	stack = ft_init(av, ac, stack, 0);
	stack->current_b = 0;
	final = stack->current_a;
	cmd = get_next_line(0);
	while (cmd)
	{
		check_move(cmd, stack);
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	if (!ft_check_sort(stack) || stack->current_a != final)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_close(stack);
}
