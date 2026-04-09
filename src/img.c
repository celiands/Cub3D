/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:27:59 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:27:59 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	new_image(t_img *img, int x, int y, t_gm *gm)
{
	img->img = mlx_new_image(gm->mlx, x, y);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ppl, &img->endian);
	img->height = y;
	img->width = x;
	return (0);
}

void	copy_image_line(int *src_line, int	*dst_line, int src_len, int dst_len)
{
	int	x;
	int	pix;

	x = 0;
	while (x < src_len && x < dst_len)
	{
		pix = src_line[x];
		if (pix)
			dst_line[x] = pix;
		x++;
	}
}

void	copy_image(t_img *dst_img, t_img *src, int sx, int sy)
{
	int	y;
	int	bytes_per_pixel;

	bytes_per_pixel = src->bpp / 8;
	y = 0;
	while (y < src->height && y + sy < dst_img->height)
	{
		copy_image_line((int *)(src->addr + y * src->ppl),
			(int *)(dst_img->addr + (y + sy) * dst_img->ppl
				+ sx * bytes_per_pixel),
			src->width, dst_img->width - sx);
		y++;
	}
}
