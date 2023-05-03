/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:19 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/01 20:36:13 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
This function first checks if the input string s is not NULL,
 since we cannot dereference a NULL pointer. 
 Then it iterates through the characters of the string using a while loop, 
 writing each character to the given file descriptor using the write system call.
  Finally, it writes a newline character '\n' to the file descriptor to add a newline at the end of the output string.
*/

// #1. The string to output.
// #2. The file descriptor on which to write.
// None
// write
// Outputs the string ’s’ to the given file
// descriptor, followed by a newline.

// Parameters
// Return value
// External functs.
// Description