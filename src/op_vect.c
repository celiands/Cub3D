/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:12:06 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/14 12:12:06 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_v2D	new2d_vect(float x, float y)
{
	t_v2D	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_v2D	rotate(t_v2D v, float deg)
{
	float	rad;
	float	cos_a;
	float	sin_a;
	t_v2D	new;

	rad = deg * (M_PI / 180.0f);
	cos_a = cosf(rad);
	sin_a = sinf(rad);
	new.x = v.x * cos_a - v.y * sin_a;
	new.y = v.x * sin_a + v.y * cos_a;
	return (new);
}

inline t_v2D	get_sq(t_v2D coords)
{
	return (new2d_vect((int)((coords.x) / TILE_SIZE),
		(int)((coords.y) / TILE_SIZE)));
}
