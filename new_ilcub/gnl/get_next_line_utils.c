/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:00 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/12 14:35:22 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	gnl_bzero(void *s, size_t n)
// {
// 	int		i;
// 	size_t	j;
// 	char	*f;

// 	f = s;
// 	i = 0;
// 	j = 0;
// 	while (j < n)
// 	{
// 		f[i] = 0;
// 		i++;
// 		j++;
// 	}
// }

// void	*gnl_calloc(size_t count, size_t size)
// {
// 	char	*crazy;

// 	crazy = (char *)malloc(size * count);
// 	if (!crazy)
// 		return (NULL);
// 	gnl_bzero(crazy, size * count);
// 	return (crazy);
// }

// char	*gnl_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0' || s[i] == c)
// 	{
// 		if (s[i] == c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	return (NULL);
// }

// size_t	gnl_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*gnl_strjoin(char const *s1, char const *s2)
// {
// 	size_t		k;
// 	size_t		j;
// 	size_t		r;
// 	size_t		i;
// 	char		*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	k = 0;
// 	j = 0;
// 	r = gnl_strlen(s2);
// 	i = gnl_strlen(s1);
// 	str = (char *)malloc((i + r + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	while (s1[k] && k < i)
// 	{
// 		str[k] = s1[k];
// 		k++;
// 	}
// 	while (s2[j] && k < (i + r))
// 		str[k++] = s2[j++];
// 	str[k] = '\0';
// 	return (str);
// }

int	ft_strlen_n(char *s, int j, int *i)
{
	while (s[*i] && s[*i] != '\n')
	{
		*i = *i + 1;
		j++;
	}
	return (j);
}

char	*free_memory(char **line)
{
	if (*(line)[0])
		return (*line);
	else
	{
		free(*line);
		return (NULL);
	}
}

// void	*gnl_memset(void *b, int c, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		((unsigned char *)b)[i] = c;
// 		i++;
// 	}
// 	return (b);
// }