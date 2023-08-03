/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:30:10 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/03 19:17:38 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->len_a)
	{
		j = i;
		while (++j < stack->len_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				free(stack->stack_a);
				free(stack->stack_b);
				ft_error();
			}
		}
	}
	
}

int	check_char(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		++i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	while(mtx[++i])
		free(mtx[i]);
	free(mtx);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
