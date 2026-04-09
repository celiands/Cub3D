/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:14 by cde-bard          #+#    #+#             */
/*   Updated: 2025/07/15 18:22:05 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
//create a substring of size len

static int	nxt_wrd(char const *s, char c, int i)
{
	while (s[i] != c && s[i])
		i++;
	while (s[i] == c && c != 0)
		i++;
	return (i);
}
//skip all the c characters

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c && c != 0)
		i++;
	while (s[i])
	{
		words++;
		i = nxt_wrd(s, c, i);
	}
	return (words);
}
//return the number of words

static int	wrdlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}
//return the size of the word

static char	**freed_everything(char **splitted, int wrd_nbr)
{
	while (wrd_nbr > 0)
	{
		wrd_nbr--;
		free(splitted[wrd_nbr]);
	}
	free(splitted);
	return (0);
}
//free all the mallocs

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		wrd_nbr;

	i = 0;
	wrd_nbr = 0;
	if (!s)
		return (0);
	splitted = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splitted)
		return (0);
	while (s[i] == c && c != 0)
		i++;
	while (s[i])
	{
		splitted[wrd_nbr] = ft_substr(s, i, wrdlen(s, c, i));
		if (!splitted[wrd_nbr])
			return (freed_everything(splitted, wrd_nbr));
		wrd_nbr++;
		i = nxt_wrd(s, c, i);
	}
	splitted[wrd_nbr] = 0;
	return (splitted);
}
