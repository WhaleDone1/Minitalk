/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:26:39 by bcarpent          #+#    #+#             */
/*   Updated: 2024/03/05 14:19:46 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(long nb)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb *= 0.1;
			size++;
		}
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	size;
	long	nb;
	char	*s;

	size = count_digits((long)n);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	nb = (long)n;
	s[size] = '\0';
	while (size > 0)
	{
		s[size - 1] = (nb % 10 + '0');
		nb *= 0.1;
		size--;
	}
	return (s);
}
