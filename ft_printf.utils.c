/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:25:36 by yokten            #+#    #+#             */
/*   Updated: 2023/01/05 14:28:01 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(long long nbr, int base, int u)
{
	int	count;

	count = 1;
	if (0 > nbr)
	{
		if (nbr == -2147483648)
			return (ft_putstr("-2147483648"));
		ft_putchar('-');
		count++;
	}
	if (nbr >= base)
		count += ft_putnbr(nbr / base, base, u);
	if (u == 0)
		write(1, &"0123456789abcdef"[nbr % base], 1);
	else
		write(1, &"0123456789ABCDEF"[nbr % base], 1);
	return (count);
}

int	ft_pointer(long long nbr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr(nbr, 16, 0);
	return (count);
}
