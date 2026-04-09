/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:26:04 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/19 14:09:08 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	print_x_recursif(char *str, unsigned long int x, int *i, char *base)
{
	if (x > 15)
		print_x_recursif(str, x / 16, i, base);
	str[*i] = base[x % 16];
	*i = *i + 1;
}

int	print_p(unsigned long int p)
{
	int		i;
	char	str[16];

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = 2;
	str[0] = '0';
	str[1] = 'x';
	print_x_recursif(str, p, &i, "0123456789abcdef");
	str[i] = 0;
	ft_putstr_fd(str, 1);
	return (i);
}

int	print_x(unsigned int x, char *base)
{
	int		i;
	char	str[14];

	i = 0;
	print_x_recursif(str, x, &i, base);
	str[i] = 0;
	ft_putstr_fd(str, 1);
	return (i);
}
