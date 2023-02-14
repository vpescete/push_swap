/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:05 by vpescete          #+#    #+#             */
/*   Updated: 2023/01/29 10:33:35 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
	{
		res = malloc(1);
		*res = 0;
		return (res);
	}
	i = 0;
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (0);
	while (i < len)
	{
		*(res + i) = s[start + i];
		i++;
	}
	*(res + i) = 0;
	return (res);
}
