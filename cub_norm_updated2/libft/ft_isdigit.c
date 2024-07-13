/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:05:56 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 10:01:07 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks whether the value of 'c' is numerical */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
