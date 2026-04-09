/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_scdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:33:39 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/19 14:10:56 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s);

int	print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_s(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	print_d(int d)
{
	char	*str;
	int		size;

	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

static void	print_u_recursif(char *str, unsigned int u, int *i)
{
	if (u > 9)
		print_u_recursif(str, u / 10, i);
	str[*i] = u % 10 + '0';
	*i = *i + 1;
}

int	print_u(unsigned int u)
{
	int		i;
	char	str[11];

	i = 0;
	print_u_recursif(str, u, &i);
	str[i] = 0;
	ft_putstr_fd(str, 1);
	return (i);
}
