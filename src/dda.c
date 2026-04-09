/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:34:41 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/27 11:35:10 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_init(t_dda *ifdda, int step[], int map[])
{
	if (ifdda->dirx < 0)
	{
		step[0] = -1;
		ifdda->sidedistx = (ifdda->posx - map[0]) * ifdda->deltadistx;
	}
	else
	{
		step[0] = 1;
		ifdda->sidedistx = ((float)map[0] + 1.0f - ifdda->posx)
			* ifdda->deltadistx;
	}
	if (ifdda->diry < 0)
	{
		step[1] = -1;
		ifdda->sidedisty = (ifdda->posy - map[1]) * ifdda->deltadisty;
	}
	else
	{
		step[1] = 1;
		ifdda->sidedisty = ((float)map[1] + 1.0f - ifdda->posy)
			* ifdda->deltadisty;
	}
}

static void	dda_perform(t_dda *ifdda, int map[], int step[], t_gm *g)
{
	while (g->tb_c->tb[map[1]][map[0]] == 0)
	{
		if (ifdda->sidedistx <= ifdda->sidedisty)
		{
			ifdda->sidedistx += ifdda->deltadistx;
			map[0] += step[0];
			ifdda->ray.side = 0;
		}
		else
		{
			ifdda->sidedisty += ifdda->deltadisty;
			map[1] += step[1];
			ifdda->ray.side = 1;
		}
	}
}

static t_uv	dda_end(t_dda *ifdda, t_img *dst)
{
	double	perpwalldist;

	if (ifdda->ray.side == 0)
		perpwalldist = (ifdda->sidedistx - ifdda->deltadistx);
	else
		perpwalldist = (ifdda->sidedisty - ifdda->deltadisty);
	ifdda->ray.hit.x = (ifdda->posx + ifdda->dirx * perpwalldist) * TILE_SIZE;
	ifdda->ray.hit.y = (ifdda->posy + ifdda->diry * perpwalldist) * TILE_SIZE;
	if (dst)
		put_pixel(dst, (int)ifdda->ray.hit.x, (int)ifdda->ray.hit.y, RAY_COLOR);
	return (get_uvx_sq(ifdda->ray, perpwalldist));
}

t_uv	dda(t_v2D o, t_v2D dir, t_img *dst, t_gm *g)
{
	int		map[2];
	int		step[2];
	t_dda	ifdda;

	ifdda.ray.origin = o;
	dir = new2d_vect(dir.x, -dir.y);
	ifdda.posx = o.x / TILE_SIZE;
	ifdda.posy = o.y / TILE_SIZE;
	ifdda.dirx = dir.x / TILE_SIZE;
	ifdda.diry = dir.y / TILE_SIZE;
	if (ifdda.dirx == 0)
		ifdda.deltadistx = 1e30;
	else
		ifdda.deltadistx = fabs(1.0f / ifdda.dirx);
	if (ifdda.diry == 0)
		ifdda.deltadisty = 1e30;
	else
		ifdda.deltadisty = fabs(1.0f / ifdda.diry);
	ifdda.ray.side = 0;
	map[0] = (int)floorf(ifdda.posx);
	map[1] = (int)floorf(ifdda.posy);
	dda_init(&ifdda, step, map);
	dda_perform(&ifdda, map, step, g);
	return (dda_end(&ifdda, dst));
}
