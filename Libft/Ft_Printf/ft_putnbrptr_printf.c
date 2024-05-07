/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrptr_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:44:04 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/05 14:20:24 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_putprint_ptr(unsigned long long n)
{
	int	is_stdout_open;

	if (n >= 16)
	{
		ft_putprint_ptr(n / 16);
		ft_putprint_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			is_stdout_open = ft_putchar_printf(n + '0');
		else
			is_stdout_open = ft_putchar_printf(n - 10 + 'a');
	}
	return (is_stdout_open);
}

int	ft_putnbrptr_printf(unsigned long long p)
{
	int	len;
	int	is_stdout_open;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	is_stdout_open = write(1, "0x", 2);
	if (is_stdout_open < 0)
		return (-1);
	len += 2;
	is_stdout_open = ft_putprint_ptr(p);
	if (is_stdout_open < 0)
		return (-1);
	len += ft_ptr_len(p);
	return (len);
}
