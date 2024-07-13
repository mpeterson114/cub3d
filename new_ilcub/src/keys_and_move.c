/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:31:44 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/06/29 21:05:02 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_program *cub, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = cub->angle_view + direction * M_PI / 2;
	dx = LINEAR_STEP * cos(angle);
	dy = LINEAR_STEP * sin(angle);
	dist = find_nearest_wall_distance(cub, calc_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = find_nearest_wall_distance(cub, (1 - (calc_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	// dist = find_nearest_wall_distance(cub, angle);
	// if (dist * dist < dy * dy + dx * dx)
	// 	if (calc_sign(dy) * calc_sign(dx) != 0)
	// 		dy = 0.0f;
	cub->pos_x += dx;
	cub->pos_y -= dy;
}

int	keys(int keycode, t_program *cub)
{
	if (keycode == ESC_KEY)
		cleanup_and_exit(cub);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		move_player(cub, 0);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		move_player(cub, 2);
	else if (keycode == ARROW_LEFT)
		cub->angle_view -= ANGLE_STEP * M_PI;
	else if (keycode == ARROW_RIGHT)
		cub->angle_view += ANGLE_STEP * M_PI;
	else if (keycode == KEY_A)
		move_player(cub, 3);
	else if (keycode == KEY_D)
		move_player(cub, 1);
	else
		return (0);
	render_scene(cub);
	return (0);
}

int	cleanup_and_exit(t_program *cub)
{
	int	i;

	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	i = -1;
	while (++i < 4)
		if (cub->textures[i].img)
			mlx_destroy_image(cub->mlx, cub->textures[i].img);
	free_all(cub);
	exit(0);
}
