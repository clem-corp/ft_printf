/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:54:10 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 07:14:28 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	argp;
	int		len;

	va_start(argp, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			len++;
		}
		else
		{
			choose_print(format, argp, &len);
			format++;
		}
		format++;
	}
	va_end(argp);
	return (len);
}

int		choose_print(const char *format, va_list argp, int *len)
{
	if (!format)
		return (-1);
	else if (*format == '%' && *(format + 1) == 'c')
		ft_char_prnt(argp, len);
	else if (*format == '%' && *(format + 1) == 's')
		ft_str_prnt(argp, len);
	else if (*format == '%' && (*(format + 1) == 'i' || *(format + 1) == 'd'))
		ft_nbr_sign_prnt(argp, len);
	else if (*format == '%' && *(format + 1) == 'u')
		ft_usi_prtn(argp, len);
	else if (*format == '%' && *(format + 1) == 'p')
		ft_hex_prnt(argp, len);
	else if (*format == '%' && (*(format + 1) == 'x' || *(format + 1) == 'X')) //oupsi
		ft_hexa_prnt(argp, len, *(format + 1));
	else if (*format == '%' && *(format + 1) == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
	return (0);
}

// char
void	ft_char_prnt(va_list argp, int *len)
{
	int c;

	c = va_arg(argp, int);
	write(1, &c, 1);
	*len += 1;
}

void	ft_str_prnt(va_list argp, int *len)
{
	char *c;

	c = va_arg(argp, char *);
	if (!c)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (*c)
		{
			write(1, c, 1);
			*len += 1;
			c++;
		}
	}
}

// nbr
void	ft_nbr_sign_prnt(va_list argp, int *len)
{
	long	nb;

	nb = va_arg(argp, int);
	if (nb < 0)
	{
		write(1 , "-", 1);
		nb *= -1;
		*len += 1;
	}
	ft_nbr_prnt(nb, len);
}

void	ft_usi_prtn(va_list argp, int *len)
{
	long	nb;

	nb = va_arg(argp, unsigned int);
	ft_nbr_prnt(nb, len);
}

void	ft_nbr_prnt(long nb, int *len)
{
	if(nb > 9)
	{
		ft_nbr_prnt(nb / 10, len);
		ft_putchar_fd(nb % 10 + '0', 1);
		*len +=1;
	}
	else
	{
		ft_putchar_fd(nb % 10 + '0', 1);
		*len +=1;
	}
}

// hexa
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
