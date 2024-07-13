/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:28:06 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 08:44:49 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling_floor(t_program *cub)
{
	unsigned int	*image_ptr;
	unsigned int	i;

	image_ptr = (unsigned int *) cub->img.addr;
	i = WIN_WIDTH * WIN_HEIGHT / 2 + 1;
	while (--i > 0)
		*image_ptr++ = cub->color_ceiling;
	i = WIN_WIDTH * WIN_HEIGHT / 2 + 1;
	while (--i > 0)
		*image_ptr++ = cub->color_floor;
}

void	render_vertical_line(t_program *cub, int image_column, float dist)
{
	unsigned int	*image_ptr;
	unsigned int	*texture_ptr;
	unsigned int	h;
	float			txt_start_point;
	float			txt_increment;

	h = (float) WIN_HEIGHT / dist;
	txt_start_point = 0.0f;
	txt_increment = (float) cub->textures[cub->txt_idx].height / h;
	if (h > WIN_HEIGHT)
	{
		txt_start_point = 0.5f * (h - WIN_HEIGHT) / h * cub->textures[cub->txt_idx].height;
		h = WIN_HEIGHT;
	}
	texture_ptr = (unsigned int *) cub->textures[cub->txt_idx].addr;
	texture_ptr += (int)((float) cub->txt_w * cub->textures[cub->txt_idx].width);
	image_ptr = (unsigned int *) cub->img.addr + image_column + (WIN_HEIGHT - h) / 2 * WIN_WIDTH;
	while (h-- > 0)
	{
		*image_ptr = *(texture_ptr + ((int)txt_start_point) * cub->textures[cub->txt_idx].width);
		image_ptr += WIN_WIDTH;
		txt_start_point += txt_increment;
	}
}

void	render_scene(t_program *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	draw_ceiling_floor(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.img);
}
