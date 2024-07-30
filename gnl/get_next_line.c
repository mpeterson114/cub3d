/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:10 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 09:48:36 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_line2(char *b, char **line)
{
	char	*line2;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (b[i + j] && b[i + j] != '\n')
		j++;
	line2 = malloc(j + 1 + (b[i + j] == '\n'));
	if (!line2)
		return (free_memory(line));
	j = 0;
	while (b[i] && b[i] != '\n')
	{
		line2[j] = b[i];
		i++;
		j++;
	}
	if (b[i] == '\n')
		line2[j++] = '\n';
	line2[j] = 0;
	return (line2);
}

static char	*join_lines(char *line, char *b)
{
	char	*line2;
	char	*line3;

	line2 = make_line2(b, &line);
	line3 = ft_strjoin(line, line2);
	free(line);
	free(line2);
	line = line3;
	return (line);
}

static char	*create_new_line(char *line)
{
	free(line);
	line = malloc(2);
	line[0] = '\n';
	line[1] = '\0';
	return (line);
}

static char	*check_buffer(char *line, int fd, char *b)
{
	static int	i;
	int			j;
	int			ret;

	if (b[i] == '\n')
		i++;
	j = 0;
	while (b[i] != '\n')
	{
		if (b[i] == 0)
		{
			ret = read(fd, b, BUFFER_SIZE);
			if (ret <= 0)
				return (free_memory(&line));
			b[ret] = 0;
			i = 0;
		}
		line = join_lines(line, b + i);
		j = ft_strlen_n(b, j, &i);
	}
	if (j == 0 && b[i] == '\n')
		line = create_new_line(line);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	b[BUFFER_SIZE + 1];

	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
	{
		ft_memset(b, 0, BUFFER_SIZE);
		return (NULL);
	}
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = check_buffer(line, fd, b);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
