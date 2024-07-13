/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:14:51 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 08:54:33 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_view_angle(t_program *cub, const char c)
{
	if (c == 'E')
		cub->angle_view = 0.0f * M_PI;
	else if (c == 'N')
		cub->angle_view = 0.5f * M_PI;
	else if (c == 'W')
		cub->angle_view = 1.0f * M_PI;
	else if (c == 'S')
		cub->angle_view = -0.5f * M_PI;
}

void	find_position(t_program *cub)
{
	int	i;
	int	j;

	i = -1;

	while (++i < cub->only_map_h)
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (ft_strchr("NSWE", cub->map[i][j]))
			{
				cub->pos_x = (float) j + 0.5f;
				cub->pos_y = (float) i + 0.5f;
				initialize_view_angle(cub, cub->map[i][j]);
				return ;
			}
		}
	}
}

void	txt_initialisation(t_program *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cub->textures[i].img = mlx_xpm_file_to_image(cub->mlx,
				cub->path_nswe[i], &cub->textures[i].width, &cub->textures[i].height);
		if (!cub->textures[i].img)
		{
			ft_putstr_fd("Error:\nCan not read the texture '", 2);
			ft_putstr_fd(cub->path_nswe[i], 2);
			ft_putstr_fd("'\n"N, 2);
			cleanup_and_exit(cub);
		}
		cub->textures[i].addr = mlx_get_data_addr(cub->textures[i].img,
				&cub->textures[i].bits_per_pixel, &cub->textures[i].line_length,
				&cub->textures[i].endian);
	}
}

void	start_game(t_program *cub)
{
	find_position(cub);
	cub->mlx = mlx_init();
	txt_initialisation(cub);
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	render_scene(cub);
	mlx_hook(cub->win, ON_KEYDOWN, KeyPressMask, keys, cub);
	mlx_hook(cub->win, ON_DESTROY, NoEventMask, cleanup_and_exit, cub);
	mlx_loop(cub->mlx);
}
