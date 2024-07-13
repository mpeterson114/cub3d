/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:13:54 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 08:53:39 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# ifdef __APPLE__
#  include "../mlx_mac/mlx.h"
#  define ARROW_UP		126
#  define ARROW_DOWN	125
#  define ARROW_LEFT	123
#  define ARROW_RIGHT	124
#  define KEY_W			13
#  define KEY_A			0
#  define KEY_S			1
#  define KEY_D			2
#  define ESC_KEY		53
#  define KEY_Q			12
# elif __linux
#  include "../mlx_linux/mlx.h"
#  define ARROW_UP		65362
#  define ARROW_DOWN	65364
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
#  define KEY_W			119
#  define KEY_A			97
#  define KEY_S			115
#  define KEY_D			100
#  define ESC_KEY		65307
#  define KEY_Q			113
# else
#  error Stop compilation: unknown system
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define Y				"\001\033[93m\002"
# define BOLD			"\001\033[1m\002"
# define R				"\001\033[91m\002"
# define P				"\001\033[35m\002"
# define G				"\001\033[0;92m\002"
# define B				"\001\033[0;94m\002"
# define N				"\001\e[0m\002"

enum e_identifiers
{
    NO,
    SO,
    WE,
    EA,
    F,
    C,
    ERROR
};

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

}	t_rgb;

typedef struct s_img
{
	void	*img; 
	char	*addr; 
	int		bits_per_pixel; 
	int		line_length;
	int		endian; 
	int		width;
	int		height;
}	t_img;

typedef struct s_program
{
	int		max_h;
	char	*path_nswe[4];
	char	**map;
	int		only_map_h;

	int		color_ceiling;
	int		color_floor;

	float	pos_x;
	float	pos_y;
	float	angle_view;
	float	txt_w;
	int		txt_idx;

	void	*mlx;
	void	*win;
	t_img	img;
	t_img	textures[4];
}	t_program;

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

# define WIN_WIDTH		640
# define WIN_HEIGHT		480
# define ANGLE_STEP		0.02f
# define LINEAR_STEP	0.3f
# define FOV			1.047f

enum {
	ON_KEYDOWN = 2, 
	ON_DESTROY = 17 
};

enum {
	NoEventMask = 0L,
	KeyPressMask = 1L<<0,
	KeyReleaseMask = 1L<<1,
	ButtonPressMask	= 1L<<2,
	ButtonReleaseMask = 1L<<3,
	EnterWindowMask	= 1L<<4,
	LeaveWindowMask = 1L<<5,
	PointerMotionMask = 1L<<6,
	PointerMotionHintMask = 1L<<7,
	Button1MotionMask = 1L<<8,
	Button2MotionMask = 1L<<9,
	Button3MotionMask = 1L<<10,
	Button4MotionMask = 1L<<11,
	Button5MotionMask = 1L<<12,
	ButtonMotionMask = 1L<<13,
	KeymapStateMask = 1L<<14,
	ExposureMask = 1L<<15,
	VisibilityChangeMask = 1L<<16,
	StructureNotifyMask = 1L<<17,
	ResizeRedirectMask = 1L<<18,
	SubstructureNotifyMask = 1L<<19,
	SubstructureRedirectMask = 1L<<20,
	FocusChangeMask = 1L<<21,
	PropertyChangeMask = 1L<<22,
	ColormapChangeMask = 1L<<23,
	OwnerGrabButtonMask = 1L<<24
};

char		**ft_free_matrix(char **matrix);
void		free_all(t_program *game);
void		error_exit(t_program *game, int i);
int			calc_sign(float f);
int			ft_get_matrix_size(char **matrix);
int			ft_longest_line(char **matrix);
int			my_atoi(t_program *game, char *str);
int			ft_get_matrix_size(char **matrix);

void		parser(char **argv, t_program *cub);
char		**read_file(char **argv, t_program *cub);

void    	map_values(t_program *cub, char **contents);
void		check_walls(t_program *cub, char **map);


void		find_position(t_program *game);
void		txt_initialisation(t_program *game);
void		start_game(t_program *game);

void		render_vertical_line(t_program *game, int w, float dist);
void		render_scene(t_program *game);

float		find_nearest_wall_distance(t_program *game, float v);
void		raycasting(t_program *game);

void		move_player(t_program *game, int direction);
int			keys(int keycode, t_program *game);
int			cleanup_and_exit(t_program *game);



#endif
