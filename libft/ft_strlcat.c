/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:19:04 by cde-bard          #+#    #+#             */
/*   Updated: 2024/11/25 11:57:08 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlcat_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlcat_strlen(dst);
	if (siz > dst_len)
	{
		while (src[i] != 0 && i < siz - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = 0;
	}
	if (dst_len > siz)
		dst_len = siz;
	return (ft_strlcat_strlen(src) + dst_len);
}
