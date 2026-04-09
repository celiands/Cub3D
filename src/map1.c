/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:12:53 by cde-bard          #+#    #+#             */
/*   Updated: 2025/10/27 11:12:57 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//verifier fail calloc
int	make_tb_c_celian(t_list_map list_map, t_gm *gm)
{
	int	i;

	gm->tb_c->m_y = list_map.m_y;
	gm->tb_c->m_x = list_map.m_x;
	gm->tb_c->tb = ft_calloc(gm->tb_c->m_y + 1, sizeof(char *));
	if (!gm->tb_c->tb)
		return (gm->tb_c->m_y = 0, 1);
	i = 0;
	while (i < gm->tb_c->m_y)
	{
		gm->tb_c->tb[i] = ft_calloc(gm->tb_c->m_x, sizeof(char));
		if (!gm->tb_c->tb[i])
		{
			gm->tb_c->m_y = i;
			return (1);
		}
		i++;
	}
	gm->tb_c->tb[i] = NULL;
	return (0);
}

int	parse_char(char c, t_gm *gm, int x, int y)
{
	char	str[2];

	if (c == '1')
		gm->tb_c->tb[y][x] = 1;
	else if (c == 'N' || c == 'O' || c == 'E' || c == 'S')
	{
		if (gm->p1 || new_player(x, y, c, gm))
			return (put_error(ERR_ONE_PLAYER, NULL));
	}
	else if (c != ' ' && c != '0' && c != 13)
	{
		str[0] = c;
		str[1] = 0;
		return (put_error(ERR_MAP_CHAR, str));
	}
	return (0);
}

//no allocation, return 1 if the map is incorrect
int	set_tb_c_celian(t_list *line, t_gm *gm)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < gm->tb_c->m_y)
	{
		x = 0;
		while (x < gm->tb_c->m_x && ((char *)line->val)[x]
			&& ((char *)line->val)[x] != '\n')
		{
			c = ((char *)line->val)[x];
			if (c == '1')
				gm->tb_c->tb[y][x] = 1;
			else if (parse_char(c, gm, x, y))
				return (1);
			x++;
		}
		y++;
		line = line->next;
	}
	if (gm->p1)
		return (0);
	return (put_error(ERR_ONE_PLAYER, 0));
}

//return the map in a list of string, and save the size x and y
static t_list_map	read_map(int fd)
{
	t_list_map	map;
	char		*current;
	t_list		*new;

	map.m_x = 0;
	map.m_y = 0;
	map.lines = 0;
	current = get_next_line(fd);
	while (current && is_empty(current))
	{
		free(current);
		current = get_next_line(fd);
	}
	while (current)
	{
		new = new_list(current);
		if (!new)
			return (free(current), close(fd), map);
		append(&(map.lines), new);
		map.m_y++;
		map.m_x = max_int(map.m_x, ft_strlen(current));
		current = get_next_line(fd);
	}
	return (close(fd), map);
}

//after the config part of .cub we create the world
//return 1 if failed 
// /!\ modif la verif empty line, et remplacer par un check
int	create_map_celian(t_gm *gm, int fd)
{
	t_list_map	list_map;

	list_map = read_map(fd);
	if (make_tb_c_celian(list_map, gm))
		return (freelst(&(list_map.lines)), put_error(ERR_MALLOC, "tb_c"));
	if (set_tb_c_celian(list_map.lines, gm))
		return (freelst(&(list_map.lines)), 1);
	return (freelst(&(list_map.lines)), 0);
}
