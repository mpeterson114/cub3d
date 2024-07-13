/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:51:59 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/28 11:32:02 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies 'n' bytes from the byte string 'src' to the byte string 'dst'.
	Does not control for memory overlaps (use ft_memmove in this case).
	Returns a pointer to the modified 'dst' */ 

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdst;

	if ((dst == src) || n == '\0')
	{
		return (dst);
	}
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	csrc = (const char *)src;
	cdst = (char *)dst;
	while (n--)
	{
		cdst[n] = csrc[n];
	}
	return (cdst);
}
