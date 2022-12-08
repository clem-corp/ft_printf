/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:46:50 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 06:48:18 by clacaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

// # define PRINTF_VALID_FORMATS	"cspdiuxX\%"
# define HEXALOWER	"0123456789abcdef"
# define HEXAUPPER	"0123456789ABCDEF"

// Function

int		ft_printf(const char *format, ...);
int		choose_print(const char *format, va_list argp, int *len);
void	ft_char_prnt(va_list argp, int *len);
void	ft_str_prnt(va_list argp, int *len);
void	ft_hex_prnt(va_list argp, int *len);
void	ft_hexa_prnt(va_list argp, int *len, char c);
void	ft_puthex(unsigned long n, char *base, int *len);
void	ft_nbr_sign_prnt(va_list argp, int *len);
void	ft_nbr_prnt(long nb, int *len);
void	ft_usi_prtn(va_list argp, int *len);

#endif