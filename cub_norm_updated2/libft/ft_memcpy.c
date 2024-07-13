/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:51:59 by mpeterso          #+#    #+#             */
/*   Updated: 2024/07/13 09:59:26 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdst;

	if ((dst == src) || n == '\0')
	{
		return (dst);
	}
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	csrc = (const char *)src;
	cdst = (char *)dst;
	while (n--)
	{
		cdst[n] = csrc[n];
	}
	return (cdst);
}
