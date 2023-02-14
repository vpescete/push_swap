/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:53:41 by vpescete          #+#    #+#             */
/*   Updated: 2023/01/29 10:33:35 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && i + n < len)
		{
			if (!needle[n + 1])
			{
				return ((char *)(haystack + i));
			}
			n++;
		}
		i++;
	}
	return (0);
}
