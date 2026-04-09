/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:12:20 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 23:12:20 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_gm *gm)
{
	cleanup(gm);
	return (0);
}

int	key_input(int keycode, t_gm *gm)
{
	if (keycode == 65307)
		close_window(gm);
	if (keycode == 119)
		gm->p1->p_dir.up = 1;
	if (keycode == 97)
		gm->p1->p_dir.left = 1;
	if (keycode == 115)
		gm->p1->p_dir.down = 1;
	if (keycode == 100)
		gm->p1->p_dir.right = 1;
	if (keycode == 65363)
		gm->p1->p_dir.rt_l = 1;
	if (keycode == 65361)
		gm->p1->p_dir.rt_r = 1;
	return (1);
}

int	key_output(int keycode, t_gm *gm)
{
	if (keycode == 119)
		gm->p1->p_dir.up = 0;
	if (keycode == 97)
		gm->p1->p_dir.left = 0;
	if (keycode == 115)
		gm->p1->p_dir.down = 0;
	if (keycode == 100)
		gm->p1->p_dir.right = 0;
	if (keycode == 65363)
		gm->p1->p_dir.rt_l = 0;
	if (keycode == 65361)
		gm->p1->p_dir.rt_r = 0;
	return (0);
}

void	move_loop(t_gm *gm)
{
	t_v2D	v;

	v = gm->p1->frwd;
	if (gm->p1->p_dir.up)
		move_p(v, gm);
	if (gm->p1->p_dir.down)
		move_p(new2d_vect(-v.x, -v.y), gm);
	if (gm->p1->p_dir.left)
		move_p(new2d_vect(-v.y, v.x), gm);
	if (gm->p1->p_dir.right)
		move_p(new2d_vect(v.y, -v.x), gm);
	if (gm->p1->p_dir.rt_l)
		gm->p1->frwd = rotate(v, -PLAYER_SENS);
	if (gm->p1->p_dir.rt_r)
		gm->p1->frwd = rotate(v, PLAYER_SENS);
}

int	hook_loop(t_gm *gm)
{
	render_loop(gm);
	move_loop(gm);
	return (0);
}
