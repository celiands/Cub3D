/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:16 by cde-bard          #+#    #+#             */
/*   Updated: 2025/10/27 11:13:18 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 13 || str[i] < 7)
			return (0);
		i++;
	}
	return (1);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

//return 0 if is paramed
int	is_paramed(t_gm *gm)
{
	if (gm->wi.ea.img == NULL)
		return (1);
	if (gm->wi.no.img == NULL)
		return (1);
	if (gm->wi.we.img == NULL)
		return (1);
	if (gm->wi.so.img == NULL)
		return (1);
	if (gm->wi.floor == -1)
		return (1);
	if (gm->wi.roof == -1)
		return (1);
	return (0);
}

int	conv_rgb(const char *line)
{
	int		color;
	char	**rgb;
	int		i;

	rgb = ft_split(line, ',');
	color = 0;
	i = 0;
	while (rgb[i])
	{
		color += (ft_atoi(rgb[i]) << (8 * (2 - i)));
		i++;
	}
	free_split(rgb);
	return (color);
}

int	flood_check(t_v2D trg, t_tb *tb_c)
{
	int	rt;

	rt = 0;
	if ((int)trg.x == 0 || (int)trg.x == tb_c->m_x - 1 || (int)trg.y == 0
		|| (int)trg.y == tb_c->m_y - 1 || tb_c->tb[(int)trg.y][(int)trg.x])
		return (1);
	if (!tb_c->tb[(int)trg.y][(int)trg.x])
		tb_c->tb[(int)trg.y][(int)trg.x] = 2;
	if (!tb_c->tb[(int)trg.y][((int)trg.x) + 1])
		rt = max(rt, flood_check(new2d_vect(trg.x + 1, trg.y), tb_c));
	if (!tb_c->tb[(int)trg.y][((int)trg.x) - 1])
		rt = max(rt, flood_check(new2d_vect(trg.x - 1, trg.y), tb_c));
	if (!tb_c->tb[((int)trg.y) + 1][(int)trg.x])
		rt = max(rt, flood_check(new2d_vect(trg.x, trg.y + 1), tb_c));
	if (!tb_c->tb[((int)trg.y) - 1][(int)trg.x])
		rt = max(rt, flood_check(new2d_vect(trg.x, trg.y - 1), tb_c));
	return (rt);
}
