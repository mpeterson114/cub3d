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