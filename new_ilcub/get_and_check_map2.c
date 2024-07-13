#include "cub3d.h"

/* Ensures that the 'only_map_h' count only includes map content lines
	with meaningful data (i.e., start with '1') */
void	pruning_map(t_program *cub, int ps)
{
	int	i;
	int	count;

	count = cub->only_map_h;
	i = -1;
	cub->only_map_h = 0;
	while (++i < count)
	{
		if (cub->trimmed_map[ps][0] == '1')
			cub->only_map_h++;
		ps++;
	}
}

void	inside_check_border2(t_program *cub, int i, int j)
{
	j--;
	while (cub->map[i][j])
	{
		if (cub->map[i][j] != '1')
			error_exit(cub, 10);
		j++;
	}
}

void	check_border2(t_program *cub)
{
	int	i;
	int	j;
	int	len_this_line;
	int	len_next_line;

	i = -1;
	while (++i < cub->only_map_h - 1)
	{
		len_this_line = ft_strlen(cub->map[i]);
		len_next_line = ft_strlen(cub->map[i + 1]);
		if (len_this_line > len_next_line)
		{
			j = len_next_line;
			inside_check_border2(cub, i, j);
		}
		else if (len_this_line < len_next_line)
		{
			j = len_this_line;
			inside_check_border2(cub, i + 1, j);
		}
	}
}

void	get_max_lenght(t_program *cub)
{
	int	i;
	int	len;

	i = -1;
	cub->map_l = 0;
	while (++i < cub->only_map_h)
	{
		len = ft_strlen(cub->map[i]);
		if (cub->map_l < len)
			cub->map_l = len;
	}
	if (cub->map_l < 3 || cub->only_map_h < 3)
		error_exit(cub, 7);
}
