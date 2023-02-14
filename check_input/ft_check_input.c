/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:43:10 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/13 17:29:07 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_check_stack(char *s, t_stack *stack)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 1;
	stack = malloc(sizeof(t_stack));
	stack->current_a = 0;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == 32 || s[i] == '-'))
			exit (0);
		if (s[i] == 32)
			trigger = 1;
		if (trigger == 1 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
		{
			stack->current_a++;
			trigger = 0;
		}
		i++;
	}
	return (stack);
}

void	ft_fill_stack(char *s, t_stack *stack)
{
	int i;
	int	trigger;
	int counter;

	i = 0;
	trigger = 1;
	counter = 0;
	stack->stack_a = (int *)malloc(stack->current_a * sizeof(int));
	stack->stack_b = malloc(stack->current_a * sizeof(int));
	while (s[i])
	{
		if (s[i] == 32)
			trigger = 1;
		if (trigger == 1 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
		{
			stack->stack_a[counter] = ft_atoi(s + i);
			counter++;
			trigger = 0;
		}
		i++;
	}
}

t_stack	*ft_check_av(char **av, int ac, t_stack *stack)
{
	int	i;
	int j;
	int	trigger; 

	i = 1;
	trigger = 1;
	stack = malloc(sizeof(t_stack));
	stack->current_a = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-'))
				exit(0);
			if (trigger == 0)
				j++;
			else
			{
				trigger = 0;
				stack->current_a++;
				j++;
			}	
		}
		trigger = 1;
		i++;
	}
	return (stack);
}

void	ft_fill_stack_2(char **av, int ac, t_stack *stack)
{
	int	i;
	int j;
	int	trigger; 

	i = 1;
	trigger = 1;
	stack->stack_a = malloc(stack->current_a * sizeof(int));
	stack->stack_b = malloc(stack->current_a * sizeof(int));
	while (i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (trigger == 0)
				j++;
			else
			{
				trigger = 0;
				stack->stack_a[i - 1] = ft_atoi(av[i]);
				j++;
			}
		}
		trigger = 1;
		i++;
	}
}

void	ft_check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->current_a)
	{
		while (stack->stack_a[i] != stack->stack_a[j] && j < stack->current_a)
		{
			j++;
			if (i == j)
				j++;
		}
		if (stack->stack_a[i] == stack->stack_a[j] && j < stack->current_a)
		{
			printf("Error\nThere's the same number multiple times\n");
			exit(0);
		}
		j = 0;
		i++;
	}
}
