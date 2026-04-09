/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:24:01 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:24:01 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wi	world_info_init(void)
{
	t_wi	wi;

	wi.ea.img = NULL;
	wi.no.img = NULL;
	wi.so.img = NULL;
	wi.we.img = NULL;
	wi.floor = -1;
	wi.roof = -1;
	return (wi);
}

//return 1 if failed to init
int	init_game_master(t_gm *gm)
{
	gm->p1 = NULL;
	gm->to_free = NULL;
	gm->tb_c = NULL;
	gm->m_anim.play = -1;
	gm->main_img.img = NULL;
	gm->render.img = NULL;
	gm->bg.img = NULL;
	gm->wi = world_info_init();
	gm->mlx = mlx_init();
	if (!gm->mlx)
		return (put_error(ERR_MLX, 0));
	gm->window = mlx_new_window(gm->mlx, S_SIZE_X, S_SIZE_Y, "cub3d");
	if (!gm->window)
		return (put_error(ERR_WINDOW, "cub3d"));
	if (new_image(&gm->main_img, S_SIZE_X, S_SIZE_Y, gm))
		return (put_error(ERR_IMG, "main_img"));
	if (new_image(&gm->render, S_SIZE_X, S_SIZE_Y, gm))
		return (put_error(ERR_IMG, "render"));
	if (new_image(&gm->bg, S_SIZE_X, S_SIZE_Y, gm))
		return (put_error(ERR_IMG, "BG"));
	return (0);
}

int	init_mlx_hooks(t_gm *gm)
{
	mlx_hook(gm->window, E_CLOSE_WINDOW, MASK_CLOSE_WINDOW, close_window, gm);
	mlx_do_key_autorepeatoff(gm->mlx);
	mlx_hook(gm->window, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_input, gm);
	mlx_hook(gm->window, 4, 1L << 2, mouse_input, gm);
	mlx_hook(gm->window, EVENT_KEY_UP, 1L << 1, key_output, gm);
	mlx_hook(gm->window, 6, (1L << 6), mouse_move_handler, gm);
	mlx_loop_hook(gm->mlx, hook_loop, gm);
	return (0);
}

//return 1 if failed to init
int	init_map(char *path, t_gm *gm)
{
	int	fd;

	gm->tb_c = malloc(sizeof(t_tb));
	if (!gm->tb_c)
		return (put_error(ERR_MALLOC, "tb_c"));
	gm->tb_c->m_y = 0;
	gm->tb_c->m_x = 0;
	gm->tb_c->tb = NULL;
	fd = open(path, O_RDONLY);
	if (fd <= -1)
		return (put_error(ERR_OPEN, path));
	if (read(fd, NULL, 0) != -1)
	{
		if (param_game(gm, fd))
			return (close(fd), 1);
		return (create_map_celian(gm, fd));
	}
	return (close(fd), put_error(ERR_READ, path));
}

//this funct check that everything is initialized
int	check_game(t_gm *gm);
