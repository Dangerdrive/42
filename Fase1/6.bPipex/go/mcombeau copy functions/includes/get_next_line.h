/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:41:39 by fde-alen          #+#    #+#             */
/*   Updated: 2023/12/11 19:44:11 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "pipex.h"

char	*get_next_line(int fd);
size_t	ft_strlenn(const char *str);
char	*ft_strjoinn(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);

#endif
