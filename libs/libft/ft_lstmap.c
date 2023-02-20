/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:37 by vpescete          #+#    #+#             */
/*   Updated: 2023/01/29 10:33:35 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void	(*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (lst == NULL)
		return (0);
	new_list = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst -> content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, *del);
			return (0);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst -> next;
	}
	return (new_list);
}
