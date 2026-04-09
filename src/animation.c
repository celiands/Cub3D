/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:13:15 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/22 20:13:15 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_anim	load_anim(char *path, int mf, t_v2D dim, t_gm *gm)
{
	t_anim	new;

	new.play = 0;
	new.frame = 0;
	new.maxframe = mf;
	new.fdim = dim;
	new.img.img = mlx_xpm_file_to_image(gm->mlx, path, &new.img.width,
			&new.img.height);
	if (!new.img.img)
	{
		new.play = -1;
		new.img.addr = NULL;
	}
	else
	{
		new.img.addr = mlx_get_data_addr(new.img.img, &new.img.bpp,
				&new.img.ppl, &new.img.endian);
	}
	return (new);
}

void	copy_frame(t_img *dst_img, t_anim *an, int sx, int sy)
{
	int		x;
	int		y;
	char	*dst;
	int		pix;

	y = 0;
	while (y < an->fdim.y && y + sy < dst_img->height)
	{
		x = 0;
		while (x < an->fdim.x && x + sx < dst_img->width)
		{
			pix = *(int *)(an->img.addr + (x + (int)(an->fdim.x * an->frame))
					* (an->img.bpp / 8) + y * an->img.ppl);
			if (pix != 0 && (((pix >> 24) & 0xFF) == 0))
			{
				dst = dst_img->addr + ((x + sx) * (dst_img->bpp / 8))
					+ (y + sy) * dst_img->ppl;
				*(int *)dst = pix;
			}
			x++;
		}
		y++;
	}
}

void	play_animation(t_img *dst, t_v2D coords, t_gm *gm)
{
	static int	inter_frame = 0;

	if (gm->m_anim.play == -1)
		return ;
	copy_frame(dst, &gm->m_anim, coords.x, coords.y);
	if (gm->m_anim.play == 1)
	{
		if (inter_frame < FPT)
			return (inter_frame++, (void)FPT);
		inter_frame = 0;
		gm->m_anim.frame++;
		if (gm->m_anim.frame > gm->m_anim.maxframe)
		{
			gm->m_anim.frame = 0;
			gm->m_anim.play = 0;
		}
	}
}
