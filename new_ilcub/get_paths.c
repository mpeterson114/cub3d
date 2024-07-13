#include "cub3d.h"

char	*init_path_to_resources(t_program *cub, char *string)
{
	int		i;
	char	*tmp;

	i = 1;
	while (string[++i] != '.')
	{
		if (string[i] != ' ')
			error_exit(cub, 3);
	}
	tmp = ft_strchr(string, '.');
	i = ft_strlen(tmp);
	if (tmp[1] != '/' || i < 6)
		error_exit(cub, 3);
	return (tmp);
}

int	get_path_to_resources(t_program *cub, char *string)
{
	if (string[0] == 'N' && string[1] == 'O' && string[2] == ' '
		&& cub->path_nswe[3] == NULL)
		cub->path_nswe[3] = ft_strdup(init_path_to_resources(cub, string));
	else if (string[0] == 'S' && string[1] == 'O' && string[2] == ' '
		&& cub->path_nswe[1] == NULL)
		cub->path_nswe[1] = ft_strdup(init_path_to_resources(cub, string));
	else if (string[0] == 'W' && string[1] == 'E' && string[2] == ' '
		&& cub->path_nswe[0] == NULL)
		cub->path_nswe[0] = ft_strdup(init_path_to_resources(cub, string));
	else if (string[0] == 'E' && string[1] == 'A' && string[2] == ' '
		&& cub->path_nswe[2] == NULL)
		cub->path_nswe[2] = ft_strdup(init_path_to_resources(cub, string));
	else
		error_exit(cub, 3);
	return (1);
}
