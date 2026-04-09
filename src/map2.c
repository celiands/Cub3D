/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:06 by cde-bard          #+#    #+#             */
/*   Updated: 2025/10/27 11:13:09 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_param(t_img *img, char **str, t_gm *gm, int fd)
{
	img->img = mlx_xpm_file_to_image(gm->mlx, str[1],
			&img->width, &img->height);
	if (!img->img)
	{
		put_error(ERR_OPEN, str[1]);
		free_split(str);
		close(fd);
		cleanup(gm);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->ppl, &img->endian);
}

void	param_modif(char **str, const char *var, t_gm *gm, int fd)
{
	if (ft_strncmp(var, "NO", 2) == 0)
		parse_param(&(gm->wi.no), str, gm, fd);
	if (ft_strncmp(var, "EA", 2) == 0)
		parse_param(&(gm->wi.ea), str, gm, fd);
	if (ft_strncmp(var, "SO", 2) == 0)
		parse_param(&(gm->wi.so), str, gm, fd);
	if (ft_strncmp(var, "WE", 2) == 0)
		parse_param(&(gm->wi.we), str, gm, fd);
	if (ft_strncmp(var, "F", 1) == 0)
		gm->wi.floor = conv_rgb(str[1]);
	if (ft_strncmp(var, "C", 1) == 0)
		gm->wi.roof = conv_rgb(str[1]);
}

//return 1 if failed
static bool	param_core(char **ord, char **var, t_gm *gm, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ord[i] && ft_strncmp(ord[i], var[0], 3) != 0)
		i++;
	while (var[1][j])
	{
		if (var[1][j] == '\r' || var[1][j] == '\n')
			var[1][j] = '\0';
		j++;
	}
	if (ord[i] != NULL)
		return (param_modif(var, ord[i], gm, fd), 0);
	else
		return (put_error(ERR_UKN, var[0]), free_split(var), 1);
}

//split and verify if there is 1 name and 1 param
//free current
char	**split_param(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (put_error(ERR_MALLOC, "split"), free(line), NULL);
	if (!split[0] || !split[1] || split[0][0] == '1' || split[0][0] == '0')
		return (free_split(split), put_error(ERR_PARAM, 0), free(line), NULL);
	return (free(line), split);
}

// read .cub first lines to read the params
// return 1 if param not ok
// never closes fd
int	param_game(t_gm *gm, int fd)
{
	const char	*ord[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	char		*current;
	char		**split;

	current = get_next_line(fd);
	while (current != NULL && is_paramed(gm) != 0)
	{
		if (!is_empty(current))
		{
			split = split_param(current);
			if (!split || param_core((char **)ord, split, gm, fd))
				return (1);
			free_split(split);
		}
		else
			free(current);
		if (is_paramed(gm) != 0)
			current = get_next_line(fd);
	}
	if (is_paramed(gm) != 0)
		return (put_error(ERR_PARAM, 0));
	if (current == NULL)
		return (put_error(ERR_PARAM, 0));
	return (0);
}
