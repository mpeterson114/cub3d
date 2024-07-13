/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:39:19 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/18 13:04:27 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Duplicates the given string 's1' by allocating the necessary memory and 
	performing a copy of the given string. A pointer to the new string is
	returned, or NULL if memory allocation fails. */

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (dst == 0)
		return (NULL);
	ft_memcpy(dst, s1, len);
	return (dst);
}

