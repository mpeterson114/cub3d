/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:20:33 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/25 19:40:30 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds and returns a pointer to the last occurrence of character 'c' in 
	string 's'. Returns NULL if 'c' is not found within the string */

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (length >= 0)
	{
		if ((unsigned char)s[length] == (unsigned char)c)
			return ((char *)s + length);
		length--;
	}
	return (0);
}

