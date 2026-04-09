/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:09:28 by cde-bard          #+#    #+#             */
/*   Updated: 2025/10/27 11:49:36 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cub3d.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	reset_buf_end(char *buf, int bits);
void	trim_buf_start(char *buf);
_Bool	is_in_str(char *buf, char c);
int		ft_buflen(char *buf);

char	*ft_bufjoin(char *line, char *buf)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	joined = malloc(ft_buflen(line) + ft_buflen(buf) + 1);
	if (!joined)
		return (0);
	while (line[i])
	{
		joined[i] = line[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		joined[i] = buf[j];
		i++;
		j++;
	}
	joined[i] = buf[j];
	if (joined[i] == '\n')
		joined[++i] = 0;
	return (joined);
}
//join line with buffer

char	*ft_bufdup(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(ft_buflen(buf) + 1);
	if (!line)
		return (0);
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = buf[i];
	if (line[i] == '\n')
		line[++i] = 0;
	return (line);
}
//return a line version of the buffer

_Bool	add_buf_to_line(char **line, char *buf)
{
	char	*new_line;

	if (*line == 0)
		new_line = ft_bufdup(buf);
	else
	{
		new_line = ft_bufjoin(*line, buf);
		free(*line);
	}
	*line = new_line;
	if (new_line)
		return (1);
	else
		return (0);
}
//add buffer content to the line
//if malloc fails, return 0

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE] = {0};
	char		*line;
	int			bits;

	line = 0;
	bits = BUFFER_SIZE;
	while (!is_in_str(buf, '\n') && bits == BUFFER_SIZE && BUFFER_SIZE != 0)
	{
		if (!add_buf_to_line(&line, buf))
			return (0);
		bits = read(fd, buf, BUFFER_SIZE);
	}
	reset_buf_end(buf, bits);
	if (!add_buf_to_line(&line, buf))
		return (0);
	trim_buf_start(buf);
	if (bits == -1 || ft_buflen(line) == 0)
	{
		free(line);
		line = 0;
	}
	return (line);
}
//increment the line until '\n' is in the buffer
//trim the end of the buffer if end of the file reached
//add the end of the line
//trim the end of the line from the buffer
//return the line
