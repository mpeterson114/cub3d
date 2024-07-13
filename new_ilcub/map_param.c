#include "cub3d.h"

/* Read through map once with get_next_line to count number of lines in map (height) */
void	map_height(t_program *cub, char *argv)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(cub, 11);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);  
	close(fd);
	cub->max_h = height;
}

/* Checks that parameters at beginning of map are valid and that all 6 mandatory identifiers (NO, SO
	WE, EA, C, F) are present with valid paths. 'i' counter is then in a position to start looking for 
	the start position of the map contents */
void	analizator_map(t_program *cub)
{
	int		i;
	int		count_param;

	count_param = 0;
	i = -1;
	while (++i < cub->max_h)
	{
		if ((!ft_strchr("NSWECF", cub->trimmed_map[i][0]) && count_param < 6))
			error_exit(cub, 6);
		if ((cub->trimmed_map[i][0] == 'N' || cub->trimmed_map[i][0] == 'S'
		|| cub->trimmed_map[i][0] == 'W' || cub->trimmed_map[i][0] == 'E')
			&& get_path_to_resources(cub, cub->trimmed_map[i]))
			count_param++;
		else if ((cub->trimmed_map[i][0] == 'C' || cub->trimmed_map[i][0] == 'F')
			&& get_colors(cub, cub->trimmed_map[i]))
			count_param++;
		if (count_param == 6)
			break ;
	}
	i = find_begin_map_position(cub, i);
	only_map(cub, i);
}

/* Read through map a second time with get_next_line to assign contents to orig_map,
	then trim and assign to trimmed_map */
void	read_map(t_program *cub, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	cub->orig_map = malloc(sizeof(char *) * (cub->max_h + 1));
	if (!cub->orig_map)
		error_exit(cub, 4);
	cub->trimmed_map = malloc(sizeof(char *) * (cub->max_h + 1));
	if (!cub->trimmed_map)
		error_exit(cub, 4);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(cub, 11);
	i = -1;
	while (++i < cub->max_h)
	{
		line = get_next_line(fd);
		cub->orig_map[i] = ft_strdup(line);
		cub->trimmed_map[i] = ft_strtrim(line, " ");  //strtrim2 with tabs-spaces
		free(line);
	}
	cub->orig_map[i] = NULL;
	cub->trimmed_map[i] = NULL;
	close(fd);
	analizator_map(cub);
}
