/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:53:30 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/05 10:21:37 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if ((size && nmemb > SIZE_MAX / size))
		return (0);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}
