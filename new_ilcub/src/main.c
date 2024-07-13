/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:58:08 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/12 13:22:41 by mpeterso         ###   ########.fr       */
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
	tmp = ft_strrchr(argv[1], '.'); // returns arg string starting from '.' to use with strncmp
	if (!tmp || ft_strncmp(tmp, ".cub\0", 5)) // checks that attachment is of type '.cub'
		error_exit(cub, 2);
}

void	init_struct(t_program *cub)
{
	int	i;

	cub->color_ceiling = -1; 
	cub->color_floor = -1;
	cub->only_map_h = 0; // height del mapa entera
	//cub->map_l = 0; // length del mapa entera
	i = -1;
	while (++i < 4)
	{
		cub->path_nswe[i] = NULL; 
		cub->textures[i].img = NULL;
	}
	//cub->orig_map = NULL;
	//cub->trimmed_map = NULL; // eliminara todos los espacias antes del 1
	cub->map = NULL;
	//cub->padded_copy = NULL;
	cub->win = NULL;
}

int	main(int argc, char **argv)
{
	t_program	*cub;

	cub = malloc(sizeof(t_program));
	init_struct(cub);
	check_args(argc, argv, cub);
	parser(argv, cub);
	//map_height(cub, argv[1]);
	//read_map(cub, argv[1]);
	start_game(cub);
	return (0);
}
