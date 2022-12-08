/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:22:37 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 07:32:53 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hex_prnt(va_list argp, int *len)
{
	unsigned long	n;
	char			*base;

	base = HEXALOWER;
	n = va_arg(argp, unsigned long);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*len += 5;
	}
	else
	{
		write(1, "0x", 2);
		*len += 2;
		ft_puthex(n, base, len);
	}
}

void	ft_hexa_prnt(va_list argp, int *len, char c)
{
	unsigned int	nb;
	char			*base;

	if (c == 'x')
		base = HEXALOWER;
	else if (c == 'X')
		base = HEXAUPPER;
	nb = va_arg(argp, int);
	ft_puthex(nb, base, len);
}

void	ft_puthex(unsigned long n, char *base, int *len)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base, len);
		ft_putchar_fd(base[n % 16], 1);
		*len += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*len += 1;
	}
}
