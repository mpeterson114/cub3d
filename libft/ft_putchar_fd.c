/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:20:17 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/14 10:50:39 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Writes char 'c' to the file descriptor passed as a parameter */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
