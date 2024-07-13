/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:00 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 08:56:05 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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