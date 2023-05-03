/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:19:38 by fde-alen          #+#    #+#             */
/*   Updated: 2023/04/26 20:00:45 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

func ft_strlcat(dest, src []byte, size int) int {
	destLen := len(dest)
	srcLen := len(src)
	i := 0
	for src[i] != 0 && destLen+i+1 < size {
		dest[destLen+i] = src[i]
		i++
	}
	dest[destLen+i] = 0
	if size < destLen {
		return srcLen + size
	} else {
		return srcLen + destLen
	}
}

