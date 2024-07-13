/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:41:05 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 08:55:36 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_ray(t_program *cub, t_ray *r, float current_angle)
{
	r->dx = cos(current_angle);
	r->dy = -sin(current_angle);
	r->sx = calc_sign(r->dx);
	r->sy = calc_sign(r->dy);
	r->vert_x = (int) cub->pos_x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) cub->pos_y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

static void	calculate_next_ray_step(t_program *cub, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = cub->pos_y + r->dy / r->dx * (r->vert_x - cub->pos_x);
		r->vert_dist = sqrt(pow(cub->pos_x - r->vert_x, 2.0)
				+ pow(cub->pos_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = cub->pos_x + r->dx / r->dy * (r->hor_y - cub->pos_y);
		r->hor_dist = sqrt(pow(cub->pos_x - r->hor_x, 2.0)
				+ pow(cub->pos_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

static float	calculate_wall_txt(t_program *cub, float dist, int color_idx, float w)
{
	cub->txt_idx = color_idx;
	cub->txt_w = w;
	return (dist);
}

float	find_nearest_wall_distance(t_program *cub, float current_angle)
{
	t_ray	r;

	initialize_ray(cub, &r, current_angle);
	while (1)
	{
		calculate_next_ray_step(cub, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (cub->map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1) / 2] == '1')
				return (calculate_wall_txt(cub, r.vert_dist, r.sx + 1, r.vert_w));
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (cub->map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (calculate_wall_txt(cub, r.hor_dist, r.sy + 2, r.hor_w));
			else
				r.hor_y += r.sy;
		}
	}
}

void	raycasting(t_program *cub)
{
	int		x;
	float	angle_step;
	float	current_angle;

	current_angle = cub->angle_view - FOV / 2;
	angle_step = FOV / (WIN_WIDTH - 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		render_vertical_line(cub, x, find_nearest_wall_distance(cub, current_angle) * cos(cub->angle_view - current_angle));
		current_angle += angle_step;
	}
}
