/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:19:10 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/12 17:07:49 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// // char	*read_file(int fd, char *stat_str)
// // {
// // 	char		*buffer;
// // 	int			read_chars;
// // 	char		*tmp;

// // 	read_chars = 1;
// // 	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
// // 	if (!stat_str)
// // 		stat_str = ft_calloc(1, 1);
// // 	while (!ft_strchr(stat_str, '\n') && read_chars != 0)
// // 	{
// // 		read_chars = read(fd, buffer, BUFFER_SIZE);
// // 		if (read_chars == -1)
// // 		{
// // 			free(buffer);
// // 			free(stat_str);
// // 			return (NULL);
// // 		}
// // 		buffer[read_chars] = '\0';
// // 		tmp = stat_str;
// // 		stat_str = ft_strjoin(stat_str, buffer);
// // 		free(tmp);
// // 	}
// // 	free(buffer);
// // 	return (stat_str);
// // }

// // char	*get_line(char *stat_str)
// // {
// // 	char	*nstr;
// // 	int		i;

// // 	i = 0;
// // 	if (stat_str[i] == '\0')
// // 		return (NULL);
// // 	while (stat_str[i] && stat_str[i] != '\n')
// // 		i++;
// // 	nstr = (char *)malloc(sizeof(char) * (i + 2));
// // 	if (!nstr)
// // 		return (NULL);
// // 	i = 0;
// // 	while (stat_str[i] && stat_str[i] != '\n')
// // 	{
// // 		nstr[i] = stat_str[i];
// // 		i++;
// // 	}
// // 	nstr[i] = '\0';
// // 	return (nstr);
// // }

// // char	*wow_next_line(char *stat_str)
// // {
// // 	size_t	i;
// // 	char	*next_line;
// // 	size_t	a;

// // 	if (!stat_str)
// // 		return (NULL);
// // 	i = 0;
// // 	while (stat_str[i] && stat_str[i] != '\n')
// // 		i++;
// // 	if (stat_str[i] == '\0')
// // 	{
// // 		free(stat_str);
// // 		return (NULL);
// // 	}
// // 	a = i;
// // 	next_line = (char *)malloc(sizeof(char) * ((ft_strlen(stat_str)) - i + 1));
// // 	if (!next_line)
// // 		return (NULL);
// // 	i = 0;
// // 	while (stat_str[a])
// // 		next_line[i++] = stat_str[++a];
// // 	next_line[i] = '\0';
// // 	free(stat_str);
// // 	return (next_line);
// // }

// // char	*get_next_line(int fd)
// // {
// // 	static char	*stat_str;
// // 	char		*nst;

// // 	if (fd < 0 || BUFFER_SIZE <= 0)
// // 		return (NULL);
// // 	stat_str = read_file(fd, stat_str);
// // 	if (!stat_str)
// // 		return (NULL);
// // 	nst = get_line(stat_str);
// // 	stat_str = wow_next_line(stat_str);
// // 	return (nst);
// // }

// char	*ft_line(char *str)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!str[i])
// 		return (NULL);
// 	while (str[i] != '\n' && str[i])
// 		i++;
// 	line = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (str[i] != '\n' && str[i])
// 	{
// 		line[i] = str[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_after_line(char *str)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;

// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	if (!str[i])
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	temp = (char *)malloc(sizeof(char) * (gnl_strlen(str) - i + 1));
// 	if (!temp)
// 		return (NULL);
// 	j = 0;
// 	i++;
// 	while (str[i])
// 		temp[j++] = str[i++];
// 	temp[j] = '\0';
// 	free(str);
// 	return (temp);
// }

// char	*ft_read(int fd, char *str)
// {
// 	char	*buff;
// 	int		ret;
// 	char 	*temp;

// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	ret = 1;
// 	if (!str)
// 		str = gnl_calloc(1, 1);
// 	while (!gnl_strchr(str, '\n') && ret != 0)
// 	{
// 		ret = read(fd, buff, BUFFER_SIZE);
// 		if (ret == -1)
// 		{
// 			free(buff);
// 			free(str);
// 			return (NULL);
// 		}
// 		buff[ret] = '\0';
// 		temp = str;
// 		str = gnl_strjoin(str, buff);
// 		free(temp);
// 	}
// 	free (buff);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*line;

// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	str = ft_read(fd, str);
// 	if (!str)
// 		return (NULL);
// 	line = ft_line(str);
// 	str = ft_after_line(str);
// 	return (line);
// }

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

	if (b[i] == '\n')      // if previous call ended with new line, advance past it
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
