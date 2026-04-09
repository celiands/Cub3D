/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UV.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:05:26 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/23 13:12:29 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_uvx(t_uv *rt, t_ray ray, t_v2D sv_ray)
{
	if (ray.side == 0)
	{
		rt->uv_x = ray.hit.y / TILE_SIZE;
		if (sv_ray.x >= ray.origin.x)
			rt->tex_type = EAST;
		else
		{
			rt->tex_type = WEST;
			rt->uv_x = (1.0 - rt->uv_x);
		}
	}
	else
	{
		rt->uv_x = ray.hit.x / TILE_SIZE;
		if (sv_ray.y >= ray.origin.y)
		{
			rt->tex_type = SOUTH;
			rt->uv_x = (1.0 - rt->uv_x);
		}
		else
			rt->tex_type = NORTH;
	}
}

t_uv	get_uvx_sq(t_ray ray, float dist)
{
	t_v2D	sq;
	t_uv	rt;
	t_v2D	sv_ray;

	sq = get_sq(ray.hit);
	sv_ray = ray.hit;
	ray.hit.x = ray.hit.x - sq.x * TILE_SIZE;
	ray.hit.y = ray.hit.y - sq.y * TILE_SIZE;
	set_uvx(&rt, ray, sv_ray);
	return (rt.dist = dist, rt);
}
