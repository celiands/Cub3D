/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:51:07 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/05 11:30:24 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static _Bool	is_word(const char *s2, const char *s1, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (is_word(s2, &s1[i], n - i))
			return ((char *)&s1[i]);
		i++;
	}
	if (is_word(s2, &s1[i], n - i))
		return ((char *)&s1[i]);
	return (0);
}
