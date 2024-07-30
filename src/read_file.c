/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:46:50 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/30 13:15:07 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_empty_line(char *line, t_program *cub)
{
	static unsigned int	line_count;
	static int			in_flag;
	static int			out_flag;

	if (line_count == 6 && ft_strlen(line) > 1 && !in_flag)
		in_flag = 1;
	if (line_count < 6 && ft_strlen(line) > 1)
		line_count++;
	if (ft_strlen(line) == 1 && in_flag && !out_flag)
		out_flag = 1;
	if ((ft_strlen(line) > 1 || *line != '\n') && out_flag)
		error_exit(cub, 14);
}

static char	*get_lines(int fd, t_program *cub)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		error_exit(cub, 4);
	while (line != NULL)
	{
		check_empty_line(line, cub);
		file = ft_strjoin_free(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

char	**read_file(char **argv, t_program *cub)
{
	int		fd;
	char	*file;
	char	**contents;
	char	*buffer[1];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(cub, 13);
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		error_exit(cub, 11);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(cub, 13);
	file = get_lines(fd, cub);
	close(fd);
	contents = ft_split(file, '\n');
	free(file);
	return (contents);
}
