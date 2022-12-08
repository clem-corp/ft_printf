/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printxt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:51:59 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 07:52:00 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// char
void	ft_char_prnt(va_list argp, int *len)
{
	int	c;

	c = va_arg(argp, int);
	write(1, &c, 1);
	*len += 1;
}

void	ft_str_prnt(va_list argp, int *len)
{
	char	*c;

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
