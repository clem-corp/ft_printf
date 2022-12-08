/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:22:40 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 07:30:58 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_nbr_sign_prnt(va_list argp, int *len)
{
	long	nb;

	nb = va_arg(argp, int);
	if (nb < 0)
	{
		write(1, "-", 1);
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
	if (nb > 9)
	{
		ft_nbr_prnt(nb / 10, len);
		ft_putchar_fd(nb % 10 + '0', 1);
		*len += 1;
	}
	else
	{
		ft_putchar_fd(nb % 10 + '0', 1);
		*len += 1;
	}
}
