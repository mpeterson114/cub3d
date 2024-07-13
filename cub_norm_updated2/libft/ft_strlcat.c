/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:53:30 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/27 10:33:11 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends the given string 'src' to the end of 'dst'. It will append at most dstsize - ft_strlen(dst) - 1 and 
	null-terminate the result. */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	i;

	d_len = 0;
	i = 0;
	if (dstsize == 0 && (!dst || !src))
		return (0);
	while (dst[d_len] && d_len < dstsize)
		d_len++;
	if (dstsize < d_len)
		return (dstsize + ft_strlen(src));
	while (src[i] && (i + d_len + 1) < dstsize)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if (d_len < dstsize)
		dst[d_len + i] = '\0';
	return (d_len + ft_strlen(src));
}
