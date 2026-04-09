/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:36:09 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/27 10:41:00 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_colision(t_v2D nv, t_gm *gm)
{
	if (gm->tb_c->tb[(int)(nv.y + PLAYER_SIZE)][(int)(nv.x + PLAYER_SIZE)])
		return (1);
	if (gm->tb_c->tb[(int)(nv.y + PLAYER_SIZE)][(int)(nv.x - PLAYER_SIZE)])
		return (1);
	if (gm->tb_c->tb[(int)(nv.y - PLAYER_SIZE)][(int)(nv.x + PLAYER_SIZE)])
		return (1);
	if (gm->tb_c->tb[(int)(nv.y - PLAYER_SIZE)][(int)(nv.x - PLAYER_SIZE)])
		return (1);
	return (0);
}

t_dir	newdir(void)
{
	t_dir	dir;

	dir.down = 0;
	dir.up = 0;
	dir.left = 0;
	dir.right = 0;
	dir.rt_l = 0;
	dir.rt_r = 0;
	return (dir);
}
