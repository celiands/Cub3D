/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:50:40 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:50:40 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_tile_celian(t_img *dst_img, int tile_x, int tile_y)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (++y - 1 < TILE_SIZE
		&& (y - 1 + tile_y * TILE_SIZE) < dst_img->height)
	{
		x = 0;
		while (++x - 1 < TILE_SIZE
			&& (x - 1 + tile_x * TILE_SIZE) < dst_img->width)
		{
			dst = dst_img->addr + (y - 1 + (tile_y * TILE_SIZE))
				* dst_img->ppl + (x - 1 + (tile_x * TILE_SIZE))
				* (dst_img->bpp / 8);
			if (((TILE_COLOR >> 24) & 0xFF) == 0)
				*(int *)dst = TILE_COLOR;
		}
	}
}

void	render_tiles_celian(t_tb *tab, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < tab->m_x)
	{
		y = 0;
		while (y < tab->m_y)
		{
			if (tab->tb[y][x] == 1)
				render_tile_celian(img, x, y);
			y++;
		}
		x++;
	}
}

/* render on an image, but dont put it on window
void	render_tiles(t_list *list, t_img *img)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		copy_t_image(img, lst->val, TILE_COLOR);
		lst = lst->next;
	}
}*/

// 0 if not in circle
static int	in_circle(int x, int y, int center, int r)
{
	int	xp;
	int	yp;

	xp = (x - center) * (x - center);
	yp = (y - center) * (y - center);
	if (xp + yp <= (r * r))
		return (1);
	return (0);
}

// put a circle in an image, that sized that image
void	put_circle(t_img *dst, int r)
{
	int		x;
	int		y;
	char	*dst_pix;

	y = 0;
	while (y < dst->height)
	{
		x = 0;
		while (x < dst->width)
		{
			if (in_circle(x, y, dst->width >> 1, r))
			{
				dst_pix = dst->addr + y
					* dst->ppl + x * (dst->bpp / 8);
				*(int *)dst_pix = PLAYER_COLOR;
			}
			x++;
		}
		y++;
	}
}
