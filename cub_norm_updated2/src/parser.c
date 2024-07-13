/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:45:18 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 10:27:33 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_valid_chars(t_program *cub, char map_val)
{
	if (map_val != '1' && map_val != '0' && map_val != 'N' && map_val != 'S'
		&& map_val != 'E' && map_val != 'W' && map_val != ' ')
		error_exit(cub, 15);
	if (map_val == 'N' || map_val == 'S' || map_val == 'E' || map_val == 'W')
		return (1);
	return (0);
}

static void	check_map_content(t_program *cub, char **map)
{
	int	x;
	int	y;
	int	found_player;

	y = 0;
	found_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			while (map[y][x] == ' ' || map[y][x] == '\t'
			|| map[y][x] == '\r' || map[y][x] == '\v'
			|| map[y][x] == '\f')
				x++;
			found_player += check_valid_chars(cub, map[y][x]);
			x++;
		}
		y++;
	}
	if (found_player > 1 || !found_player)
		error_exit(cub, 8);
}

void	parser(char **argv, t_program *cub)
{
	char	**contents;
	char	**map;
	int		i;

	contents = read_file(argv, cub);
	map_values(cub, contents);
	map = contents + 6;
	cub->only_map_h = ft_get_matrix_size(map);
	cub->map = malloc(sizeof(char *) * (cub->only_map_h + 1));
	if (!cub->map)
		error_exit(cub, 4);
	i = -1;
	while (++i < cub->only_map_h)
	{
		cub->map[i] = ft_strdup(map[i]);
		if (!cub->map[i])
		{
			error_exit(cub, 4);
			ft_free_matrix(contents);
		}
	}
	cub->map[cub->only_map_h] = NULL;
	check_map_content(cub, cub->map);
	check_walls(cub, cub->map);
	ft_free_matrix(contents);
}
