/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:01:07 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 09:57:43 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies up to 'dstsize' - 1 characters from the given
	string 'src' to the given string 'dst', null-terminating the result. */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (*src != '\0' && i < (dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
	}
	if (i < dstsize)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}
