/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:19:46 by ngauthre          #+#    #+#             */
/*   Updated: 2025/10/27 09:31:41 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_img *dst, t_gm *gm)
{
	t_img	src;

	if (new_image(&src, TILE_SIZE >> 1, TILE_SIZE >> 1, gm))
	{
		put_error(ERR_RENDER, "minimap's player");
		mlx_destroy_image(gm->mlx, dst->img);
		cleanup(gm);
	}
	put_circle(&src, TILE_SIZE >> 2);
	copy_image(dst, &src, gm->p1->x * TILE_SIZE + (src.width >> 1),
		gm->p1->y * TILE_SIZE + (src.height >> 1));
	mlx_destroy_image(gm->mlx, src.img);
}

static void	render_loop_end(t_gm *gm)
{
	play_animation(&gm->render,
		new2d_vect((S_SIZE_X >> 1) - 132, S_SIZE_Y - 264), gm);
	mlx_put_image_to_window(gm->mlx, gm->window, gm->render.img, 0, 0);
}

void	render_loop(t_gm *gm)
{
	t_img		map;
	size_t		dim;

	ft_memcpy(gm->render.addr, gm->bg.addr, S_SIZE_Y * gm->bg.ppl);
	dim = gm->main_img.height * gm->main_img.ppl;
	if (new_image(&map, gm->main_img.width, gm->main_img.height, gm))
		return (put_error(ERR_RENDER, "minimap"), cleanup(gm));
	if (MINIMAP)
	{
		ft_memcpy(map.addr, gm->main_img.addr, dim);
		render_player(&map, gm);
		draw_raycasting(new2d_vect(gm->p1->x * TILE_SIZE + (TILE_SIZE >> 1),
				gm->p1->y * TILE_SIZE + (TILE_SIZE >> 1)), gm->p1->frwd,
			&map, gm);
		copy_image(&gm->render, &map, 0, 0);
	}
	else
	{
		draw_raycasting(new2d_vect(gm->p1->x * TILE_SIZE + (TILE_SIZE >> 1),
				gm->p1->y * TILE_SIZE + (TILE_SIZE >> 1)),
			gm->p1->frwd, NULL, gm);
	}
	render_loop_end(gm);
	if (map.img)
		mlx_destroy_image(gm->mlx, map.img);
}

void	make_bg(t_gm *gm)
{
	size_t	dim;

	dim = gm->bg.height * gm->bg.ppl;
	put_pixel(&gm->bg, 10, 10, gm->wi.floor);
	fill_img(gm->bg.addr, dim >> 3, gm->wi.roof);
	fill_img(gm->bg.addr + (dim >> 1), dim >> 3, gm->wi.floor);
}
