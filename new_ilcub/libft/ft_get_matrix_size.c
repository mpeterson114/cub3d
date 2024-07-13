#include "libft.h"

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