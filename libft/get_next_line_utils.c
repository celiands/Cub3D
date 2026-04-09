/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:09:46 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/21 12:09:51 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_buflen(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	return (i);
}
//return buf length

_Bool	is_in_str(char *buf, char c)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}
//true if c is in str

void	trim_buf_start(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_buflen(buf);
	while (buf[j] != 0)
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = 0;
}
//trim the end of the previous line from the buffer

void	reset_buf_end(char *buf, int bits)
{
	if (bits == -1)
		bits = 0;
	while (buf[bits])
	{
		buf[bits] = 0;
		bits++;
	}
}
//set to 0 the unupdated end of the buffer 