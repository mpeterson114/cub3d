#include "cub3d.h"

/* Locates starting position of map contents, starting from where 'i' iterator
left off after checking for all 6 map parameters */
int	find_begin_map_position(t_program *cub, int i)
{
	while (cub->orig_map[++i])
	{
		if (cub->trimmed_map[i][0] != '\0' && cub->trimmed_map[i][0] != '1')
			error_exit(cub, 12);
		if (cub->trimmed_map[i][0] == '1')
			break ;
	}
	return (i);
}

void	check_desastr(t_program *cub, int position)
{
	int	j;

	while (++position < cub->only_map_h)
	{
		j = 0;
		while (cub->map[position][j])
		{
			if (ft_strchr(" 01NSWE", cub->map[position][j]))
				error_exit(cub, 9);
			else
				j++;
		}
	}
}

/* Ensures that the map only contains valid characters (" 01NSWE") and exactly 
	1 player */
void	check_symbol_map(t_program *cub, int ps)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (++i < cub->only_map_h)
	{
		j = 0;
		if (cub->trimmed_map[ps][j] != '1')
			check_desastr(cub, i);
		while (cub->trimmed_map[ps][j] != '\0')
		{
			if (!ft_strchr(" 01NSWE", cub->trimmed_map[ps][j]))
				error_exit(cub, 7);
			if (ft_strchr("NSWE", cub->trimmed_map[ps][j]))
				player++;
			j++;
		}
		ps++;
	}
	if (player > 1 || player == 0)
		error_exit(cub, 8);
}

void	check_border(t_program *cub)   // padded map needed to avoid leaks when map is open with adjacent 'null' space (not ' ')
{
	int	i;
	int	j;
	int	len_string;

	i = -1;
	while (++i < cub->only_map_h)
	{
		j = 0;
		len_string = ft_strlen(cub->map[i]);
		while (j < len_string)
		{
			if (ft_strchr("0NSEW", cub->map[i][j]))
			{
				if ((i == 0) || (i == cub->only_map_h - 1)
					|| (j == 0) || (cub->map[i][len_string - 1] == 0))
					error_exit(cub, 10);
				if ((cub->map[i][j - 1] == ' ') || (cub->map[i][j + 1] == ' ')
		|| (cub->map[i - 1][j] == ' ') || (cub->map[i + 1][j] == ' ')
		|| (cub->map[i - 1][j + 1] == ' ') || (cub->map[i - 1][j - 1] == ' ')
		|| (cub->map[i + 1][j + 1] == ' ') || (cub->map[i + 1][j - 1] == ' '))
					error_exit(cub, 10);
			}
			j++;
		}
	}
}

// static void paste_original(t_program *cub)
// {
//     int i;
//     int j;

// 	i = 0;
//     while (++i < cub->only_map_h + 1)
//     {
//         j = 0;
//         while (++j < (int)ft_strlen(cub->map[i - 1]) + 1)
// 		{
// 			(cub->padded_copy)[i][j] = cub->map[i - 1][j - 1];
// 		}
            
//     }
// }

// /* Creates a copy of the original map with 1 row/column of padding added around all borders, then 
// fills the map with the ' ' character */
// static void get_padded_copy(t_program *cub)
// {
//     int i;
//     int j;
//     int width;

// 	i = 0;
// 	width = ft_strlen(cub->map[i]);
//     cub->padded_copy = ft_calloc((cub->only_map_h + 3), sizeof(char *));    // adding padding for null terminator + 1 extra cell on each side of map borders
//     if (!cub->padded_copy)
//         error_exit(cub, 4);
//     i = -1;
//     while (++i < cub->only_map_h + 2)  // 'i' iterating over rows along vertical axis, +2 to include added padding cells
//     {
// 		printf("padded copy: %s\n", cub->padded_copy[i]);
//         cub->padded_copy[i] = ft_calloc(width + 3, sizeof(char)); // adding padding for null terminator + 1 extra cell on each side of map borders
//         if (!cub->padded_copy[i])
//             error_exit(cub, 4);
//         j = -1;
//         while (++j < width + 2)      // 'j' iterating over columns along horizontal axis, +2 to include added padding cells
//             cub->padded_copy[i][j] = ' ';
//         cub->padded_copy[i][j] = '\0';
//     }
//     cub->padded_copy[i] = NULL;
//     paste_original(cub);
// }

void	only_map(t_program *cub, int position)
{
	int	ps;

	ps = position;
	cub->map = malloc(sizeof(char *) * (cub->max_h + 1));
	//cub->padded_copy = ft_calloc((cub->max_h + 3), sizeof(char *));
	if (!cub->map /*|| !cub->padded_copy*/)
		error_exit(cub, 4);
	// printf("POS: %d\n", position);
	// printf("MAX_H: %d\n", cub->max_h);
	while (position < cub->max_h)
	{
		cub->map[cub->only_map_h] = cub->orig_map[position];
		//cub->padded_copy[]
		cub->only_map_h++;
		position++;
		//printf("map: %s\n", cub->map[cub->only_map_h]);
	}
	cub->map[position] = NULL;
	check_symbol_map(cub, ps);
	pruning_map(cub, ps);
	//get_padded_copy(cub);
	check_border(cub);
	check_border2(cub);
	get_max_lenght(cub);
	cub->trimmed_map = ft_free(cub->trimmed_map);
}
