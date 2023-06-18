/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:09:15 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/17 22:05:49 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>


char		*ft_itoa(int n);
char		*ft_itoa_base(long long num, int base);
int			ft_numlen_base(long long num, int base);
int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_putnbr(int n);
int			ft_print_unsigned(unsigned int n);
int			ft_printchar(char c);
int			ft_print_hex(unsigned int num, const char format);
int			ft_print_ptr(unsigned long long n);
int			ft_printf(const char *format, ...);
void		ft_putstr(char *str);
void		ft_put_hex(unsigned int n, const char format);

#endif
