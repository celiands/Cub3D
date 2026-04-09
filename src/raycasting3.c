/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:22:26 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/27 10:26:19 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	new_line(int index, t_uv uv, float ray_angle)
{
	t_line	line;

	line.index = index;
	line.ray_angle = ray_angle;
	line.uv = uv;
	return (line);
}

t_col	new_column(short line_siz, short x, t_line ifl, short lim)
{
	t_col	col;

	col.line_siz = line_siz;
	col.ifl = ifl;
	col.y = (S_SIZE_Y - line_siz) >> 1;
	col.x = x;
	col.pix_lim = lim;
	return (col);
}
