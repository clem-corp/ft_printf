/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:46:50 by clacaill          #+#    #+#             */
/*   Updated: 2022/12/08 01:08:41 by clacaill         ###   ########.fr       */
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

#endif