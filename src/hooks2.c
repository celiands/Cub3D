/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:58:52 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/22 19:58:52 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move_handler(int x, int y, t_gm *gm)
{
	const int	mx = S_SIZE_X >> 1;
	const int	my = S_SIZE_Y >> 1;

	(void)y;
	if (x != mx)
		gm->p1->frwd = rotate(gm->p1->frwd, -(PLAYER_SENS / 3.0) * (x - mx));
	mlx_mouse_move(gm->mlx, gm->window, mx, my);
	return (0);
}

int	mouse_input(int button, int x, int y, t_gm *gm)
{
	(void)x;
	(void)y;
	if (button == 1)
		gm->m_anim.play = 1;
	return (0);
}
