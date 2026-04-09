/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:13:54 by cde-bard          #+#    #+#             */
/*   Updated: 2024/12/05 12:17:22 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s);

static void	convert(char *str, unsigned int un, int *i)
{
	if (un > 9)
		convert(str, un / 10, i);
	str[*i] = un % 10 + '0';
	*i = *i + 1;
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	un;
	char			tab[13];

	i = 0;
	if (n < 0)
	{
		tab[0] = '-';
		i++;
		un = -n;
	}
	else
		un = n;
	convert(tab, un, &i);
	tab[i] = 0;
	return (ft_strdup(tab));
}
