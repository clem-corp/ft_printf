/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:54:10 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 07:29:49 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
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

int	choose_print(const char *format, va_list argp, int *len)
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
	else if (*format == '%' && (*(format + 1) == 'x' || *(format + 1) == 'X'))
		ft_hexa_prnt(argp, len, *(format + 1));
	else if (*format == '%' && *(format + 1) == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
	return (0);
}
