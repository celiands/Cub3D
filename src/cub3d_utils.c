/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:22:46 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:22:46 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_wi(t_gm *gm)
{
	if (gm->wi.ea.img)
		mlx_destroy_image(gm->mlx, gm->wi.ea.img);
	if (gm->wi.no.img)
		mlx_destroy_image(gm->mlx, gm->wi.no.img);
	if (gm->wi.we.img)
		mlx_destroy_image(gm->mlx, gm->wi.we.img);
	if (gm->wi.so.img)
		mlx_destroy_image(gm->mlx, gm->wi.so.img);
}

void	freetb(t_tb *tb_c)
{
	int	i;

	i = 0;
	if (tb_c == NULL)
		return ;
	while (i < tb_c->m_y)
	{
		free(tb_c->tb[i]);
		i++;
	}
	if (tb_c->tb)
		free(tb_c->tb);
	free(tb_c);
}

//mlx isnt null 
void	cleanup(t_gm *gm)
{
	free(gm->p1);
	free_wi(gm);
	if (gm->to_free)
		free(gm->to_free);
	if (gm->tb_c)
		freetb(gm->tb_c);
	if (gm->mlx)
	{
		if (gm->m_anim.play != -1)
			mlx_destroy_image(gm->mlx, gm->m_anim.img.img);
		if (gm->window)
			mlx_destroy_window(gm->mlx, gm->window);
		if (gm->main_img.img)
			mlx_destroy_image(gm->mlx, gm->main_img.img);
		if (gm->render.img)
			mlx_destroy_image(gm->mlx, gm->render.img);
		if (gm->bg.img)
			mlx_destroy_image(gm->mlx, gm->bg.img);
		mlx_loop_end(gm->mlx);
		mlx_destroy_display(gm->mlx);
		free(gm->mlx);
	}
	exit(0);
}

// /!\ utils
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	put_pixel(t_img *dst_img, int x, int y, int color)
{
	char	*dst;

	if (!(y < dst_img->height && x < dst_img->width) || x < 0 || y < 0)
		return ;
	dst = dst_img->addr + (x * dst_img->bpp / 8) + (y * dst_img->ppl);
	*(int *)dst = color;
}
