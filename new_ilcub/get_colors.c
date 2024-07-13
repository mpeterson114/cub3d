#include "cub3d.h"

int	my_atoi(t_program *cub, char *str)
{
	int		i;
	long	k;

	i = 0;
	k = 0;
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error_exit(cub, 5);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += ((int)str[i] - '0');
		i++;
	}
	while (str[i] && str[i] != ',')
	{
		if (str[i] != ' ')
			error_exit(cub, 5);
		i++;
	}
	if (k > 255)
		error_exit(cub, 5);
	return ((int)k);
}

void	init_color_floor_and_ceiling(t_program *cub, char *string, int i)
{
	char	*tmp;
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error_exit(cub, 4);
	if (string[1] != ' ')
		error_exit(cub, 5);
	tmp = string;
	rgb->r = my_atoi(cub, tmp);
	tmp = ft_strchr(tmp, ',');
	rgb->g = my_atoi(cub, tmp);
	++tmp;
	tmp = ft_strchr(tmp, ',');
	rgb->b = my_atoi(cub, tmp);
	if (i == 0)
		cub->color_ceiling = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	else
		cub->color_floor = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	free(rgb);
}

int	get_colors(t_program *cub, char *string)
{
	if (string[0] == 'C' && cub->color_ceiling == -1)
		init_color_floor_and_ceiling(cub, string, 0);
	else if (string[0] == 'F' && cub->color_floor == -1)
		init_color_floor_and_ceiling(cub, string, 1);
	else
		error_exit(cub, 5);
	return (1);
}
