/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:00 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 09:58:58 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds and returns a pointer to the first occurence of character 'c' 
	in string 's'. If the character is not found, the function returns
	NULL */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (((unsigned char)c) == '\0')
		return ((char *)s + i);
	return (0);
}
