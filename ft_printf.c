/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:54:10 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 01:59:53 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	argp;
	// int		i;
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
	*len += 1;
	va_arg(argp, int);
	if (!format)
		return (0);
	else if (*format == '%' && *(format + 1) == 'c')
		return (0);
	else if (*format == '%' && *(format + 1) == 's')
		return (0);
	else if (*format == '%' && *(format + 1) == 'p')
		return (0);
	else if (*format == '%' && *(format + 1) == 'd')
		return (0);
	else if (*format == '%' && *(format + 1) == 'i')
		return (0);
	else if (*format == '%' && *(format + 1) == 'u')
		return (0);
	else if (*format == '%' && *(format + 1) == 'x')
		return (0);
	else if (*format == '%' && *(format + 1) == 'X')
		return (0);
	else if (*format == '%' && *(format + 1) == '%')
		return (0);
	return (0);
/* 	{
		write(1, "%", 1);
		*len += 1;
	} */
	// else if (*format == '%' && *(format + 1) == '')
}

int main(void)
{
	printf("Donnez la valeur de a :");
	return (0);
}