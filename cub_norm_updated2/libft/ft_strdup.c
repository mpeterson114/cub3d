/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:39:19 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 09:58:48 by ilzhabur         ###   ########.fr       */
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
