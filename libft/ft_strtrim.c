/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:03:56 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/05 12:33:11 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

static _Bool	isinstr(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
//return true if c is in set

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (set[0] == '\0')
		return (ft_substr(s1, start, end + 1));
	while (isinstr(s1[start], set))
	{
		start++;
	}
	if (s1[start] == '\0')
		return (ft_calloc(1, 1));
	while (isinstr(s1[end], set) && end > 0)
		end--;
	return (ft_substr(s1, start, end + 1 - start));
}
