/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:28:06 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/06/29 19:58:55 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	llena la mitad superior de la imagen con el color del techo y la mitad 
	inferior con el color del suelo, utilizando los colores definidos en 
	cub->color_ceiling y cub->color_floor, respectivamente.
*/
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

/*
	mapear y dibujar una textura verticalmente sobre una línea en la imagen de salida
*/
void	render_vertical_line(t_program *cub, int image_column, float dist)
{
	unsigned int	*image_ptr; // puntero que se mueve a través de la imagen de salida, píxel por píxel
	unsigned int	*texture_ptr; // apuntar al inicio de una matriz de datos que representa una imagen de textura
	unsigned int	h; // Calcula la altura en píxeles de la línea en la pantalla
	float			txt_start_point;
	float			txt_increment; // Calcula el cambio en el índice de textura por cada píxel que avanza verticalmente en la pantalla (h). Esto asegura que la textura se mapee correctamente sobre la línea en función de su distancia y perspectiva.

	h = (float) WIN_HEIGHT / dist;
	txt_start_point = 0.0f;
	txt_increment = (float) cub->textures[cub->txt_idx].height / h;
	// se realiza un ajuste para mantener la proporción de la textura. txt_start_point 
	// se desplaza hacia arriba para centrar la textura, y h se establece en WIN_HEIGHT para evitar 
	// que la línea vertical supere los límites de la pantalla
	if (h > WIN_HEIGHT)
	{
		txt_start_point = 0.5f * (h - WIN_HEIGHT) / h * cub->textures[cub->txt_idx].height;
		h = WIN_HEIGHT;
	}
	texture_ptr = (unsigned int *) cub->textures[cub->txt_idx].addr;
	// calcula el desplazamiento en píxeles dentro de la textura
	texture_ptr += (int)((float) cub->txt_w * cub->textures[cub->txt_idx].width);
	// A medida que itera a lo largo de la altura h, ajusta verticalmente la posición de la textura 
	// en función de txt_start_point y txt_increment, asegurando así un mapeo correcto y proporcional de la textura sobre la línea renderizada.
	image_ptr = (unsigned int *) cub->img.addr + image_column + (WIN_HEIGHT - h) / 2 * WIN_WIDTH;
	while (h-- > 0)
	{
		*image_ptr = *(texture_ptr + ((int)txt_start_point) * cub->textures[cub->txt_idx].width);
		// imprimir colores en vez de txt
		// if (cub->txt_idx == 1)
		// 	*image_ptr = 0xFFFFFF;
		// else if (cub->txt_idx == 0)
		// 	*image_ptr = 0x00ff00;
		// else if (cub->txt_idx == 2)
		// 	*image_ptr = 0xFFFF00;
		// else
		// 	*image_ptr = 0xFF3010;
		image_ptr += WIN_WIDTH;
		txt_start_point += txt_increment;
	}
}

/*
	permite redibujar la ventana gráfica con los colores del entorno y el resultado del 
	ray casting en cada iteración del ciclo de renderizado.
*/
void	render_scene(t_program *cub)
{
	// Crea una nueva imagen en memoria con dimensiones WIN_WIDTH x WIN_HEIGHT
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	// Obtiene el puntero a los datos de la imagen para poder modificarla
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	draw_ceiling_floor(cub);
	// Realiza el renderizado principal (en este caso, ray casting)
	raycasting(cub);
	// Muestra la imagen en la ventana cub->win en las coordenadas (0, 0)
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	// Destruye la imagen creada para liberar memoria
	mlx_destroy_image(cub->mlx, cub->img.img);
}
