/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:09:15 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/24 15:49:47 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NO_FLAG (0)

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char		*ft_itoa_base(long long num, int base);
int			ft_numlen_base(long long num, int base);
int			ft_printstr(char *str);
int			ft_print_nbr(int num, const char flag);
int			ft_print_unsigned(unsigned int n);
int			ft_printchar(char c);
int			ft_print_hex(unsigned int num, const char format, const char flag);
int			ft_print_ptr(unsigned long long num);
int			ft_printf(const char *frmt, ...);
void		ft_string_toupper(char *str);

#endif
