/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:45:09 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 10:28:02 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_walls_check(char **copy_map, t_program *cub)
{
	int	i;
	int	j;	

	i = -1;
	while (++i < (ft_get_matrix_size(copy_map)))
	{
		j = -1;
		while (++j < (int)ft_strlen(copy_map[i]))
		{
			if (copy_map[i][j] == '0' || copy_map[i][j] == 'N'
				|| copy_map[i][j] == 'S' || copy_map[i][j] == 'W'
				|| copy_map[i][j] == 'E')
			{
				if (copy_map[i][j + 1] == ' ' || copy_map[i][j - 1] == ' '
					|| copy_map[i + 1][j] == ' ' || copy_map[i - 1][j] == ' ')
				{
					ft_free_matrix(copy_map);
					error_exit(cub, 10);
				}
			}
		}
	}
}

static void	paste_original(char **map, char ***copy_map, t_program *cub)
{
	int	i;
	int	j;

	i = 0;
	while (++i < cub->only_map_h + 1)
	{
		j = 0;
		while (++j < (int)ft_strlen(map[i - 1]) + 1)
			(*copy_map)[i][j] = map[i - 1][j - 1];
	}
}

static char	**get_map_copy(t_program *cub, char **map)
{
	int		i;
	int		j;
	int		width;
	char	**copy_map;

	width = ft_longest_line(map);
	copy_map = ft_calloc((cub->only_map_h + 3), sizeof(char *));
	if (!copy_map)
		error_exit(cub, 4);
	i = -1;
	while (++i < cub->only_map_h + 2)
	{
		copy_map[i] = ft_calloc(width + 3, sizeof(char));
		if (!copy_map[i])
			error_exit(cub, 4);
		j = -1;
		while (++j < width + 2)
			copy_map[i][j] = ' ';
		copy_map[i][j] = '\0';
	}
	copy_map[i] = NULL;
	paste_original(map, &copy_map, cub);
	return (copy_map);
}

void	check_walls(t_program *cub, char **map)
{
	char	**copy_map;

	copy_map = get_map_copy(cub, map);
	copy_walls_check(copy_map, cub);
	ft_free_matrix(copy_map);
}
