/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:08:06 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/19 21:08:23 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*now;

	now = *lst;
	while (now)
	{
		next = now -> next;
		ft_lstdelone(now, del);
		now = next;
	}
	*lst = 0;
}
