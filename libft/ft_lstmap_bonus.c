/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:34:10 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/19 19:34:37 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_dup;
	t_list	*new;

	lst_dup = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
		{
			ft_lstclear(&lst_dup, del);
			return (0);
		}
		ft_lstadd_back(&lst_dup, new);
		lst = lst -> next;
	}
	return (lst_dup);
}
