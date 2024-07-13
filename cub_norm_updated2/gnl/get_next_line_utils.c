/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:00 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 09:49:35 by ilzhabur         ###   ########.fr       */
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
