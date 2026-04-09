/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:09 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/12 17:14:58 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (src < dest)
	{
		while (i < n)
		{
			((char *)dest)[n - i - 1] = ((const char *)src)[n - i - 1];
			i++;
		}
		return (dest);
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
		return (dest);
	}
}
