/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:09:15 by fde-alen          #+#    #+#             */
/*   Updated: 2023/07/11 17:40:59 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NO_FLAG (0)

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

// auxiliary functions
char		*ft_itoa(int num);
int			ft_numlen(int num);
char		*ft_uitoa_base(unsigned long num, int base, const char format);
int			ft_unumlen_base(unsigned long num, int base);
// print type functions
int			ft_print_char(char c);
int			ft_print_hex(unsigned int num, const char format, const char flag);
int			ft_print_nbr(int num, const char flag);
int			ft_print_ptr(unsigned long int num);
int			ft_print_str(char *str);
int			ft_print_unsigned(unsigned int num);
// ft_print
int			ft_printf(const char *frmt, ...);

#endif

