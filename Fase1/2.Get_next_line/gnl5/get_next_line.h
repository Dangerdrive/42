/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:39 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/31 22:16:47 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_text(int fd, char *line_buffer);
char	*extract_line(char *line_buffer);
char	*extract_remaining(char *line_buffer);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);

#endif