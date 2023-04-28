/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:50:44 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/28 18:01:24 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sign);
}
/*
	   The  calloc()  function allocates memory for an array of nmemb elements
       of size bytes each and returns a pointer to the allocated memory.   The
       memory  is  set  to zero.  If nmemb or size is 0, then calloc() returns
       either NULL, or a unique pointer value that can later  be  successfully
       passed to free().  If the multiplication of nmemb and size would result
       in integer overflow, then calloc() returns an error.  By  contrast,  an
       integer  overflow  would  not be detected in the following call to mal‐
       loc(), with the result that an incorrectly sized block of memory  would
       be allocated:


*/