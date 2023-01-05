/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:50:38 by yokten            #+#    #+#             */
/*   Updated: 2023/01/05 14:26:38 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putconverter(char c, va_list av)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(av, int));
	else if (c == 's')
		count += ft_putstr(va_arg(av, char *));
	else if (c == 'd' || c == 'i')
			count += ft_putnbr(va_arg(av, int), 10, 0);
	else if (c == 'u')
		count += ft_putnbr(va_arg(av, unsigned int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr(va_arg(av, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr(va_arg(av, unsigned int), 16, 1);
	else if (c == 'p')
		count += ft_pointer(va_arg(av, unsigned long));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	av;
	int		count;

	count = 0;
	va_start(av, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_putconverter(*(str + 1), av);
			str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(av);
	return (count);
}
/* 
int main(void)
{
	int a;
	char b;
	int retWE = 0;
	int ret = 0;

	a = 19;
	b = 'S';
	retWE = ft_printf("decimal: %d\n char: %c\nint : %i\n decimal: %d\n %x\n %p\n %X\n % \n", a, b, a, b, a, &a, a);
	ret = printf("decimal: %d\n char: %c\nint : %i\n decimal: %d\n %x\n %p\n %X\n % \n", a, b, a, b, a, &a, a);
	printf("%d\n%d\n", ret, retWE);
	return 0;
} */
