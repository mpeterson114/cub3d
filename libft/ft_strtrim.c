/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:31:22 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/27 11:40:36 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Removes any characters of the given 'set' from the beginning and end 
	of the given string 's1', and allocates sufficient memory to store 
	the trimmed copy of the string. */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && (ft_strchr(set, s1[i]) != NULL))
		i++;
	while ((ft_strchr(set, s1[j]) != NULL) && j > i)
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
