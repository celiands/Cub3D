/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:52:43 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/23 16:52:43 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	make_tb_c(t_gm *gm)
{
	int i;

	gm->tb_c->tb = malloc(sizeof(int *) * (gm->tb_c->m_y + 1));
	if (!gm->tb_c->tb)
		return (1);
	i = 0;
	while (i < gm->tb_c->m_y)
	{
		gm->tb_c->tb[i] = malloc(sizeof(int) * (gm->tb_c->m_x));
		if (!gm->tb_c->tb[i])
		{
			gm->tb_c->m_y = i;
			return (1);
		}
		ft_memset(gm->tb_c->tb[i], 0, gm->tb_c->m_x * sizeof(int));
		i++;
	}
	gm->tb_c->tb[i] = NULL;
	return (0);
}*/

/*void	set_tb_c(t_gm *gm)
{
	t_list	*lst;
	t_tile	*t;

	lst = gm->cols;
	while (lst != NULL)
	{
		t = lst->val;
		gm->tb_c->tb[t->y][t->x] = 1;
		lst = lst->next;
	}
}*/

t_tb	*tb_cpy(t_tb *tb)
{
	t_tb	*new;
	int		i;

	new = malloc(sizeof(t_tb));
	if (!new)
		return (NULL);
	new->m_x = tb->m_x;
	new->m_y = tb->m_y;
	new->tb = malloc(sizeof(char *) * new->m_y);
	if (!new->tb)
		return (free(new), NULL);
	i = 0;
	while (i < new->m_y)
	{
		new->tb[i] = malloc(sizeof(char) * new->m_x);
		if (!new->tb[i])
		{
			new->m_y = i;
			return (freetb(new), NULL);
		}
		ft_memcpy(new->tb[i], tb->tb[i], new->m_x * sizeof(char));
		i++;
	}
	return (new);
}
