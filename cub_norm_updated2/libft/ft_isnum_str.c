/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:00:55 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/05/18 15:00:57 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isnum_str(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        else
            s++;
    }
    return (1);
}