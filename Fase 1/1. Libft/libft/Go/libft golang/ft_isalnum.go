/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/25 21:50:09 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

func ft_isalnum(c int) bool {
	return unicode.IsLetter(rune(c)) || unicode.IsDigit(rune(c))
}

/*
This Go function takes an integer value as an argument and returns a boolean value. It uses the unicode.IsLetter and unicode.IsDigit functions from the built-in unicode package to check if the provided integer is a letter or a digit. If the provided value is a letter or a digit, it returns true, else false. Note that this Go function uses rune instead of int type for its argument to handle Unicode characters correctly.
*/