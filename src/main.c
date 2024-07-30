/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:58:08 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 10:27:19 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv, t_program *cub)
{
	char	*tmp;

	if (!cub)
		error_exit(cub, 4);
	if (argc != 2)
		error_exit(cub, 1);
	tmp = ft_strrchr(argv[1], '.');
	if (!tmp || ft_strncmp(tmp, ".cub\0", 5))
		error_exit(cub, 2);
}

void	init_struct(t_program *cub)
{
	int	i;

	cub->color_ceiling = -1;
	cub->color_floor = -1;
	cub->only_map_h = 0;
	i = -1;
	while (++i < 4)
	{
		cub->path_nswe[i] = NULL;
		cub->txt[i].img = NULL;
	}
	cub->map = NULL;
	cub->win = NULL;
}

int	main(int argc, char **argv)
{
	t_program	*cub;

	cub = malloc(sizeof(t_program));
	init_struct(cub);
	check_args(argc, argv, cub);
	parser(argv, cub);
	start_game(cub);
	return (0);
}
