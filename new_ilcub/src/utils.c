#include "cub3d.h"

char	**ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

void	free_all(t_program *cub)
{
	int	count;

	// if (cub->orig_map)
	// 	cub->orig_map = ft_free(cub->orig_map);
	// if (cub->trimmed_map)
	// 	cub->trimmed_map = ft_free(cub->trimmed_map);
	if (cub->map)
		ft_free_matrix(cub->map);
	// if (cub->padded_copy)
	// 	ft_free_matrix(cub->padded_copy);
	count = -1;
	while (++count < 4)
	{
		if (cub->path_nswe[count])
			free(cub->path_nswe[count]);
	}
	free(cub);
}

static void	error_exit2(int i)
{
	if (i == 11)
		ft_putstr_fd("Error\nFile cannot be read\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nAfter NO, SO, WE, EA, C, F must be map\n", 2);
	else if (i == 13)
		ft_putstr_fd("Error\nFile cannot be opened\n", 2);
	else if (i == 14)
		ft_putstr_fd("Error\nInvalid line distribution (ex: Empty line in map, texture lines duplicated or out of place)\n", 2);
	else if (i == 15)
		ft_putstr_fd("Error\nInvalid character found in map\n", 2);
}

void	error_exit(t_program *cub, int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nInvalid # of args (ex: ./cub3d maps/<map of choice>)\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nMap file must be of type \".cub\"\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nWrong path to resources \"NO,SO,WE,EA\"\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMemory allocation error\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nValues of color [0,255] or not correct dates\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nCheck parametres -> NO, SO, WE, EA, C, F\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nMap not valid\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nInvalid player amount: Map must have 1 player \'S W E N\'\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nNot valid ending map\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error\nCheck borders in map\n", 2);
	else
		error_exit2(i);
	free_all(cub);
	exit(i);
}

int	calc_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

int ft_get_matrix_size(char **matrix)
{
    int count;

    count = 0;
    while (*matrix)
    {
        count++;
        matrix++;
    }
    return (count);
}

int ft_longest_line(char **matrix)
{
    int i;
    int max_length;

    max_length = INT_MIN;
    while (*matrix)
    {
        i = 0;
        while ((*matrix)[i])
            i++;
        if (i > max_length)
            max_length = i;
        matrix++;
    }
    return (max_length);
}

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
