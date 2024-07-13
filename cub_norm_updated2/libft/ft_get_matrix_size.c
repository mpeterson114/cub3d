/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:02:14 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/13 10:02:55 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_matrix_size(char **matrix)
{
	int	count;

	count = 0;
	while (*matrix)
	{
		count++;
		matrix++;
	}
	return (count);
}
