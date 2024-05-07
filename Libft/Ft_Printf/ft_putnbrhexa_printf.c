/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:26 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/05 14:20:13 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static int	ft_putprint_hex(unsigned int n, const char format)
{
	int	is_stdout_open;

	is_stdout_open = 0;
	if (n >= 16)
	{
		ft_putprint_hex(n / 16, format);
		ft_putprint_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			is_stdout_open = ft_putchar_printf(n + '0');
		else
		{
			if (format == 'x')
				is_stdout_open = ft_putchar_printf(n - 10 + 'a');
			if (format == 'X')
				is_stdout_open = ft_putchar_printf(n - 10 + 'A');
		}
	}
	return (is_stdout_open);
}

int	ft_putnbrhexa_printf(unsigned int n, const char format)
{
	int	is_stdout_open;

	if (n == 0)
	{
		is_stdout_open = write(1, "0", 1);
		if (is_stdout_open < 0)
			return (-1);
		return (1);
	}
	else
	{
		is_stdout_open = ft_putprint_hex(n, format);
		if (is_stdout_open < 0)
			return (-1);
	}
	return (ft_hexa_len(n));
}
