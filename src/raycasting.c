/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:08:10 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/13 11:08:10 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	tex_selector(int tex, t_img **src, t_gm *gm)
{
	if (tex == -1)
		return (0);
	else if (tex == 0)
		*src = &gm->wi.we;
	else if (tex == 1)
		*src = &gm->wi.so;
	else if (tex == 2)
		*src = &gm->wi.no;
	else
		*src = &gm->wi.ea;
	return (1);
}

int	get_pix(t_v2D uv, t_gm *gm, int tex)
{
	t_img	*src;
	char	*pixel_ptr;
	int		x;
	int		y;

	src = NULL;
	if (!tex_selector(tex, &src, gm))
		return (0);
	x = (int)(uv.x * (src->width - 1));
	y = (int)(uv.y * (src->height - 1));
	if (x < 0)
		x = 0;
	if (x >= src->width)
		x = src->width - 1;
	if (y < 0)
		y = 0;
	if (y >= src->height)
		y = src->height - 1;
	pixel_ptr = src->addr + (y * src->ppl) + (x * (src->bpp / 8));
	return (*(int *)pixel_ptr);
}
