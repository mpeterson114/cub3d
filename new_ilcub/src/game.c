/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:14:51 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/12 17:55:01 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Este ángulo se utiliza luego para calcular la dirección en la que el jugador 
	está mirando dentro del juego.
*/
static void	initialize_view_angle(t_program *cub, const char c)
{
	// El ángulo de visión se establece en 0.0 radianes, lo que significa que el jugador mira hacia la derecha (Este).
	if (c == 'E')
		cub->angle_view = 0.0f * M_PI;
	// El ángulo de visión se establece en 0.5 * M_PI radianes (π/2), lo que significa que el jugador mira hacia arriba (Norte).
	else if (c == 'N')
	// El ángulo de visión se establece en 1.0 * M_PI radianes (π), lo que significa que el jugador mira hacia la izquierda (Oeste).
		cub->angle_view = 0.5f * M_PI;
	else if (c == 'W')
	// El ángulo de visión se establece en -0.5 * M_PI radianes (-π/2), lo que significa que el jugador mira hacia abajo (Sur).
		cub->angle_view = 1.0f * M_PI;
	else if (c == 'S')
		cub->angle_view = -0.5f * M_PI;
}


/*
	recorre el mapa hasta encontrar la posición inicial del jugador 
	('N', 'S', 'W', 'E'), estableciendo sus coordenadas y ángulo de visión para 
	inicializar el estado del juego.
*/
void	find_position(t_program *cub)
{
	int	i;
	int	j;

	i = -1;

	while (++i < cub->only_map_h) // 19
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (ft_strchr("NSWE", cub->map[i][j]))
			{
				// i y j es la posicion en la matriz
				// Añade 0.5f a j para centrar horizontalmente al jugador dentro del tile
				cub->pos_x = (float) j + 0.5f;
				cub->pos_y = (float) i + 0.5f;
				initialize_view_angle(cub, cub->map[i][j]);
				return ;
			}
		}
	}
}

/*
	carga las texturas
*/
void	txt_initialisation(t_program *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		// carga una imagen en formato XPM desde un archivo y la convierte en un formato 
		// que puede ser utilizado por MiniLibX para renderizado gráfico
		cub->textures[i].img = mlx_xpm_file_to_image(cub->mlx,
				cub->path_nswe[i], &cub->textures[i].width, &cub->textures[i].height);
		if (!cub->textures[i].img)
		{
			ft_putstr_fd("Error:\nCan not read the texture '", 2);
			ft_putstr_fd(cub->path_nswe[i], 2);
			ft_putstr_fd("'\n"N, 2);
			cleanup_and_exit(cub);
		}
		// crea un puntero para acceder a los datos de la imagen en memoria
		cub->textures[i].addr = mlx_get_data_addr(cub->textures[i].img,
				&cub->textures[i].bits_per_pixel, &cub->textures[i].line_length,
				&cub->textures[i].endian);
	}
}



void	start_game(t_program *cub)
{
	find_position(cub);
	// incializa la conexión con el servidor gráfico y prepara el entorno 
	// necesario para crear y manejar ventanas y gráficos utilizando la biblioteca MiniLibX.
	cub->mlx = mlx_init();
	txt_initialisation(cub);
	// crea una nueva ventana en MiniLibX
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	render_scene(cub);
	mlx_hook(cub->win, ON_KEYDOWN, KeyPressMask, keys, cub);
	mlx_hook(cub->win, ON_DESTROY, NoEventMask, cleanup_and_exit, cub);
	mlx_loop(cub->mlx);
}
