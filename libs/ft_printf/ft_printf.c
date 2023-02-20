/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:53:55 by vpescete          #+#    #+#             */
/*   Updated: 2022/12/30 15:52:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char *s, int i, va_list args)
{
	int	l;

	l = 0;
	if (s[i] == 'c')
		l += ft_putchar((char)va_arg(args, int));
	else if (s[i] == 's')
		l += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		l += ft_putnbr(va_arg(args, int));
	else if (s[i] == 'p')
		l += ft_print_pt_pn(va_arg(args, unsigned long), "0123456789abcdef");
	else if (s[i] == 'u')
		l += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		l += ft_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		l += ft_hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s[i] == '%')
		l += ft_putchar('%');
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			l += ft_check_type(s, i + 1, args);
			i++;
		}
		else
			l += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (l);
}
