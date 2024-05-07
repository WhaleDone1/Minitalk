/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:27:57 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/05 14:20:00 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(va_list paramslist, const char format)
{
	unsigned int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_printf(va_arg(paramslist, int));
	else if (format == 's')
		len += ft_putstr_printf(va_arg(paramslist, char *));
	else if (format == 'p')
		len += ft_putnbrptr_printf(va_arg(paramslist, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_printf(va_arg(paramslist, int));
	else if (format == 'u')
		len += ft_putnbru_printf(va_arg(paramslist, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_putnbrhexa_printf(va_arg(paramslist, unsigned int), format);
	else if (format == '%')
		len += ft_putchar_printf('%');
	return (len);
}

static int	ft_printf_strchr(va_list paramslist, const char *s)
{
	int				i;
	int				is_stdout_open;
	unsigned int	len;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			is_stdout_open = ft_printf_format(paramslist, s[i + 1]);
			if (is_stdout_open < 0)
				return (-1);
			i++;
		}
		else
		{
			is_stdout_open = ft_putchar_printf(s[i]);
			if (is_stdout_open < 0)
				return (-1);
		}
		len += is_stdout_open;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	paramslist;
	int		len;

	va_start(paramslist, s);
	len = ft_printf_strchr(paramslist, s);
	if (len < 0)
	{
		va_end(paramslist);
		write(2, "Error\n", 6);
		return (-1);
	}
	else
	{
		va_end(paramslist);
		return (len);
	}
}
