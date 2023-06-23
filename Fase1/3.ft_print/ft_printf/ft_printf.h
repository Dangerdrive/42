/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:09:15 by fde-alen          #+#    #+#             */
/*   Updated: 2023/06/22 22:43:37 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_HASH (1 << 0) // Flag A is stored in the first bit position
# define FLAG_SPACE (1 << 1) // Flag B is stored in the second bit position
# define FLAG_PLUS (1 << 2) // Flag C is stored in the third bit position
# define NO_FLAG (0)

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>


char		*ft_itoa(int n);
char		*ft_itoa_base(long long num, int base);
int			ft_numlen_base(long long num, int base);
int			ft_printstr(char *str);
// int			ft_print_nbr(int n);
int			ft_print_nbr(int num, const char flag);
int			ft_print_unsigned(unsigned int n);
int			ft_printchar(char c);
int			ft_print_hex(unsigned int num, const char format, const char flag);
int			ft_print_ptr(unsigned long long num);
int			ft_printf(const char *frmt, ...);
//void		ft_putstr(char *str);
void		ft_put_hex(unsigned int n, const char format);
void		ft_string_toupper(char *str);


#endif
