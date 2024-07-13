/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:52:15 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/28 11:31:53 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies 'n' bytes from memory area 'src' to memory
	area 'dst', where memory areas may overlap. If the 'dst' pointer is found
	to be between the 'src' pointer and the index 'n', copying will be done
	back to front to prevent data being modified before being copied.
	Otherwise it will be done front to back	to preserve data. */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*csrc;
	char		*cdst;

	if (dst == src)
	{
		return (dst);
	}
	csrc = (const char *)src;
	cdst = (char *)dst;
	if (csrc < cdst)
	{
		while (len--)
		{
			*(cdst + len) = *(csrc + len);
		}
		return (cdst);
	}
	while (len--)
	{
		*cdst++ = *csrc++;
	}
	return (dst);
}
