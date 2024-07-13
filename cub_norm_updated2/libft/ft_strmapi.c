/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:18:36 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 09:56:51 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the given function 'f' to each character
	in the given string 's' and allocates sufficient memory to store the
	resulting new string. */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}
