/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:59:03 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/27 10:28:52 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//draw player direction's ray
void	draw_ray(t_v2D o, t_v2D dir, t_img *dst)
{
	int	i;

	i = 0;
	o.x += dir.x;
	o.y -= dir.y;
	while (i < TILE_SIZE)
	{
		if (dst)
			put_pixel(dst, o.x, o.y, RAY_COLOR);
		o.x += dir.x;
		o.y -= dir.y;
		i++;
	}
}

static void	print_col(short i, t_img *dest, t_col ifc, t_gm *gm)
{
	register short	j;
	int				pix;

	j = 0;
	pix = get_pix(new2d_vect(ifc.ifl.uv.uv_x, (float)i / (float)ifc.line_siz),
			gm, ifc.ifl.uv.tex_type);
	while (j <= ifc.pix_lim && (ifc.x + j < dest->width && ifc.x + j >= 0))
	{
		put_pixel(dest, ifc.x + j, ifc.y + i, pix);
		j++;
	}
}

static void	put_line(t_img *dest, t_line ifl, t_gm *gm)
{
	short			line_siz;
	register short	i;
	short			x;
	short			y;
	short			pix_lim;

	line_siz = (S_SIZE_Y / (ifl.uv.dist * cos(ifl.ray_angle
					* M_PI / 180.0f))) * TILE_SIZE;
	i = 0;
	x = ((ifl.index) / ACCURACY) + (S_SIZE_X >> 1) - 1;
	y = (S_SIZE_Y - line_siz) >> 1;
	pix_lim = (int)(1.0 / ACCURACY);
	if (y < 0)
		i = -y;
	while (i < line_siz && y + i < dest->height)
	{
		print_col(i, dest, new_column(line_siz, x, ifl, pix_lim), gm);
		i++;
	}
}

void	draw_raycasting(t_v2D v, t_v2D dir, t_img *dst, t_gm *gm)
{
	short				nb_ray;
	float				ang_per_ray;
	register short		i;

	nb_ray = S_SIZE_X * ACCURACY;
	ang_per_ray = POV / (float)nb_ray;
	draw_ray(v, dir, dst);
	i = 0;
	put_line(&gm->render, new_line(0, dda(v, dir, dst, gm), ang_per_ray * i),
		gm);
	while (i <= nb_ray / 2)
	{
		put_line(&gm->render, new_line(-i, dda(v, rotate(dir, ang_per_ray * i),
					dst, gm), ang_per_ray * i), gm);
		put_line(&gm->render, new_line(i, dda(v, rotate(dir, -ang_per_ray * i),
					dst, gm), ang_per_ray * i), gm);
		i++;
	}
}
