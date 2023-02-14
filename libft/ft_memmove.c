/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:44:31 by vpescete          #+#    #+#             */
/*   Updated: 2023/01/29 10:33:35 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

//int	main()
//{
//	int	bf1[] = {1,2,3,4,5,6,7,8,9,10, '\0'};
//	int	bf2[] = {1,2,3,4,5,6,7,8,9,10, '\0'};
//	int i;
//
//	i = 0;
//	memmove(bf1 + 2, bf1, sizeof(int) * 8);
//	ft_memmove(bf2 + 2, bf2, sizeof(int) * 8);
//	while (bf1[i])
//	{
//		printf("i=%d, num=%d, indirizzo=%p\n", i, bf1[i], &bf1[i]);
//		i++;
//	}
//	i = 0;
//	while (bf2[i])
//	{
//		printf("i=%d, num=%d\n", i, bf2[i]);
//		i++;
//	}
//}
