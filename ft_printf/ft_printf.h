/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:24:18 by vpescete          #+#    #+#             */
/*   Updated: 2022/12/30 15:49:57 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_unsigned_putnbr(unsigned int nb);
int	ft_hex_putnbr(unsigned int nb, char *hex);
int	ft_pt_putnbr(unsigned long nb, char *hex);
int	ft_print_pt_pn(unsigned long nb, char *hex);
int	ft_check_type(const char *s, int i, va_list args);
int	ft_printf(const char *s, ...);

#endif