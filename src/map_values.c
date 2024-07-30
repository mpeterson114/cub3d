/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:45:15 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 10:27:54 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static enum	e_identifiers	get_line_values(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "NO\t", 3))
		return (NO);
	if (ft_strnstr(line, "SO ", 3) || ft_strnstr(line, "SO\t", 3))
		return (SO);
	if (ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "WE\t", 3))
		return (WE);
	if (ft_strnstr(line, "EA ", 3) || ft_strnstr(line, "EA\t", 3))
		return (EA);
	if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "F\t", 2))
		return (F);
	if (ft_strnstr(line, "C ", 2) || ft_strnstr(line, "C\t", 2))
		return (C);
	return (ERROR);
}

static char	*get_texture_path(char *line, t_program *cub)
{
	char	*texture_path;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	line += 2;
	texture_path = ft_strtrim(line, " \t");
	if (!ft_strlen(texture_path))
	{
		free(texture_path);
		error_exit(cub, 6);
	}
	return (texture_path);
}

void	init_color_floor_and_ceiling(t_program *cub, char *line,
	enum e_identifiers type_id)
{
	char	*tmp;
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error_exit(cub, 4);
	if (line[1] != ' ')
		error_exit(cub, 5);
	tmp = line;
	rgb->r = my_atoi(cub, tmp);
	tmp = ft_strchr(tmp, ',');
	rgb->g = my_atoi(cub, tmp);
	++tmp;
	tmp = ft_strchr(tmp, ',');
	rgb->b = my_atoi(cub, tmp);
	if (type_id == C)
		cub->color_ceiling = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	else
		cub->color_floor = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	free(rgb);
}

void	map_values(t_program *cub, char **contents)
{
	int					i;
	enum e_identifiers	type_id;

	i = 0;
	while (i < 6)
	{
		type_id = get_line_values(contents[i]);
		if (type_id == ERROR)
			error_exit(cub, 6);
		if (type_id == NO && cub->path_nswe[3] == NULL)
			cub->path_nswe[3] = get_texture_path(contents[i], cub);
		else if (type_id == SO && cub->path_nswe[1] == NULL)
			cub->path_nswe[1] = get_texture_path(contents[i], cub);
		else if (type_id == WE && cub->path_nswe[0] == NULL)
			cub->path_nswe[0] = get_texture_path(contents[i], cub);
		else if (type_id == EA && cub->path_nswe[2] == NULL)
			cub->path_nswe[2] = get_texture_path(contents[i], cub);
		else if (type_id == F && cub->color_floor == -1)
			init_color_floor_and_ceiling(cub, contents[i], type_id);
		else if (type_id == C)
			init_color_floor_and_ceiling(cub, contents[i], type_id);
		i++;
	}
}
