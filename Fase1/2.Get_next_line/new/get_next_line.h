/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:32:41 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/30 13:33:40 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # include <unistd.h>
// # include <stdlib.h>

// char	*get_next_line(int fd);
// size_t	ft_strlen(const char *str);
// size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
// size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
// char	*ft_strdup(const char *src);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char const *s1, char const *s2);
// void	ft_strcpy(char *dest, const char *src);
// char	*ft_substr(const char *s, unsigned int start, size_t len);


// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_remaining(int fd, char *remaining);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *remaining, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *remaining);
char	*ft_new_remaining(char *remaining);

#endif
