/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:45 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/27 11:43:08 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills 'n' bytes of data with '/0' within the string 's'. If n=0, 
	bzero does nothing */  

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
