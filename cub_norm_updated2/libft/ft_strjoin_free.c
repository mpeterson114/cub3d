#include "libft.h"

/* Concatenates the given strings 's1' and 's2'and allocates sufficient memory 
	for the newly created string. Frees s1. Returns a pointer to the new combined string, 
	or NULL if memory allocation fails */

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_str = (char *)malloc(len);
	if (new_str == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}	
	j = 0;
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (new_str);
}