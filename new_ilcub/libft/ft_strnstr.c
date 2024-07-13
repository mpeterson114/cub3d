/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:28:57 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/27 11:52:00 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Searches the first 'n' bytes of the given string 's1' for the first 
	occurence of the full string 's2'. Characters that appear after \0 are
	not searched. */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (len == 0 && (!needle || !haystack))
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	h = 0;
	while (haystack[h] && h < len)
	{
		if (haystack[h] == needle[0])
		{
			n = 0;
			while (needle[n] != '\0' && h + n < len)
			{
				if (haystack[h + n] == needle[n] && needle[n + 1] == '\0')
					return ((char *)&haystack[h]);
				else if (haystack[h + n] != needle[n])
					break ;
				n++;
			}
		}
		h++;
	}
	return (NULL);
}

