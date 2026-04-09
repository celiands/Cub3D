/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:57:49 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/05 12:38:44 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

static size_t	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(s);
	i = 0;
	if (slen < start)
		return (ft_calloc(1, 1));
	d = malloc(min(len, (slen - start)) + 1);
	if (!d)
		return (0);
	while (i < len && i + start < slen)
	{
		d[i] = s[i + start];
		i++;
	}
	d[i] = 0;
	return (d);
}
