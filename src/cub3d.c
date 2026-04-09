/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:07:33 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:07:33 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_img(char *addr, size_t dim, unsigned int color)
{
	unsigned int	*pix;
	size_t			i;

	i = 0;
	pix = (unsigned int *)addr;
	while (i < dim)
		pix[i++] = color;
}

//return 1 and print the error
bool	put_error(char *err, char *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(var, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_gm	gm;
	t_tb	*past;

	if (argc < 2 || !argv[1] || ft_strlen(argv[1]) < 4
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 3) != 0)
		return (put_error(ERR_ARGS, argv[1]));
	if (init_game_master(&gm))
		cleanup(&gm);
	if (init_map(argv[1], &gm))
		cleanup(&gm);
	gm.m_anim = load_anim(GUN_ANIM, 5, new2d_vect(264, 264), &gm);
	past = tb_cpy(gm.tb_c);
	if (!past)
		return (put_error(ERR_MALLOC, "tb_cpy"), cleanup(&gm), 1);
	if (past->m_x * past->m_y > MAP_MAX_SIZE)
		return (put_error(ERR_MAP_SIZE, 0), freetb(past), cleanup(&gm), 1);
	if (flood_check(new2d_vect(gm.p1->x, gm.p1->y), past))
		return (freetb(past), put_error(ERR_MAP_CLOSE, 0), cleanup(&gm), 1);
	freetb(past);
	make_bg(&gm);
	render_tiles_celian(gm.tb_c, &gm.main_img);
	init_mlx_hooks(&gm);
	mlx_loop(gm.mlx);
	return (cleanup(&gm), 0);
}
