/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:07:52 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/13 11:07:52 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// /!\ les val sont au pif
static t_v2D	get_dir(char c)
{
	if (c == 'N')
		return (new2d_vect(0, 1));
	if (c == 'E')
		return (new2d_vect(1, 0));
	if (c == 'W')
		return (new2d_vect(-1, 0));
	return (new2d_vect(0, -1));
}

//tester fail
int	new_player(int x, int y, char dir, t_gm *gm)
{
	t_player	*new;

	new = malloc(sizeof(t_player));
	if (!new)
		return (1);
	new->x = x;
	new->y = y;
	new->frwd = get_dir(dir);
	gm->p1 = new;
	gm->p1->p_dir = newdir();
	return (0);
}
/*
// if movement is possible return 1, else 0
static int	can_move(t_v2D v, t_gm *gm)
{
	t_v2D	nv;

	nv.x = gm->p1->x + v.x * PLAYER_SPEED;
	nv.y = gm->p1->y - v.y * PLAYER_SPEED;
	return (!test_col(nv, gm));
}*/

static int	can_move_x(t_v2D v, t_gm *gm)
{
	t_v2D	nv;

	nv.x = gm->p1->x + v.x * PLAYER_SPEED + 0.5f;
	nv.y = gm->p1->y + 0.5f;
	return (!test_colision(nv, gm));
}

static int	can_move_y(t_v2D v, t_gm *gm)
{
	t_v2D	nv;

	nv.x = gm->p1->x + 0.5f;
	nv.y = gm->p1->y - v.y * PLAYER_SPEED + 0.5f;
	return (!test_colision(nv, gm));
}

void	move_p(t_v2D v, t_gm *gm)
{
	if (can_move_x(v, gm))
		gm->p1->x += v.x * PLAYER_SPEED;
	if (can_move_y(v, gm))
		gm->p1->y -= v.y * PLAYER_SPEED;
}
