/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:58:10 by yokten            #+#    #+#             */
/*   Updated: 2023/01/05 14:51:04 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long long nbr, int base, int u);
int		ft_pointer(long long nbr);

#endif