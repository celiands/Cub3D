/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:19:54 by cde-bard          #+#    #+#             */
/*   Updated: 2025/07/13 11:44:14 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (++i < n && src[i - 1])
		dst[i - 1] = src[i - 1];
	if (n > 0)
		dst[i - 1] = '\0';
	return (ft_strlen(src));
}
