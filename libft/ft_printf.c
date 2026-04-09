/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-bard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:26:49 by cde-bard          #+#    #+#             */
/*   Updated: 2025/01/19 14:10:25 by cde-bard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	print_c(int c);
int	print_s(char *s);
int	print_p(unsigned long int p);
int	print_d(int d);
int	print_u(unsigned int u);
int	print_x(unsigned int x, char *base);

static int	print_input(const char *text, int *i)
{
	int		start;
	char	*print;

	start = *i;
	while (text[*i] != '\0' && text[*i] != '%')
	{
		*i = *i + 1;
	}
	print = ft_substr(text, start, *i - start);
	ft_putstr_fd(print, 1);
	free(print);
	return (*i - start);
}
//print the texte until '%' or '\0' (update the size and the indice)

static int	convert(va_list args, char contyp)
{
	int		size;

	size = 0;
	if (contyp == 'c')
		size = print_c(va_arg(args, int));
	else if (contyp == 's')
		size = print_s(va_arg(args, char *));
	else if (contyp == 'd' || contyp == 'i')
		size = print_d(va_arg(args, int));
	else if (contyp == 'p')
		size = print_p(va_arg(args, unsigned long int));
	else if (contyp == 'u')
		size = print_u(va_arg(args, unsigned int));
	else if (contyp == 'x')
		size = print_x(va_arg(args, unsigned int), "0123456789abcdef");
	else if (contyp == 'X')
		size = print_x(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (contyp == '%')
		size = print_c('%');
	return (size);
}
//determine the type of the conversion and return the additional size

int	ft_printf(const char *text, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	if (!text)
		return (-1);
	va_start(args, text);
	while (text[i])
	{
		size += print_input(text, &i);
		if (text[i] == '%')
		{
			i = i + 2;
			size += convert(args, text[i - 1]);
		}
	}
	va_end(args);
	return (size);
}
//alternates between printext and convert
