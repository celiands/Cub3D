/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:28:57 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 23:28:57 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_tile(t_tile *tile, t_game_master *gm)
// {
// 	if (!tile)
// 		return ;
// 	mlx_destroy_image(gm->win_p.mlx, tile->img->img);
// 	free(tile->img);
// 	free(tile);
// }

// void	freelst_tiles(t_list **lst, t_game_master *gm)
// {
// 	t_list	*prev;

// 	while (lst != NULL && lst[0] != NULL)
// 	{
// 		prev = (*lst)->next;
// 		free_tile((t_tile *)(*lst)->val, gm);
// 		free(*lst);
// 		*lst = prev;
// 	}
// }

void	freelst(t_list **lst)
{
	t_list	*prev;

	if (!(*lst))
		return ;
	while (lst != NULL && lst[0] != NULL)
	{
		prev = (*lst)->next;
		free((*lst)->val);
		free(*lst);
		*lst = prev;
	}
}

// int	get_coords_tiles(t_list *lst, int x, int y)
// {
// 	if (!lst)
// 		return (-1);
// 	while (lst != NULL)
// 	{
// 		if (((t_tile *)lst->val)->x == x && ((t_tile *)lst->val)->y == y)
// 			return (((t_tile *)lst->val)->type);
// 		lst = lst->next;
// 	}
// 	return (-2);
// }
