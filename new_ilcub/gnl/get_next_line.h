/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:21:01 by ilzhabur          #+#    #+#             */
/*   Updated: 2024/07/12 14:34:56 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int	ft_strlen_n(char *s, int j, int *i);
char	*free_memory(char **line);
// void	gnl_bzero(void *s, size_t n);
// void	*gnl_calloc(size_t count, size_t size);
// char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
void	*gnl_memset(void *b, int c, size_t len);
// size_t	gnl_strlen(const char *s);
// char	*read_file(int fd, char *stat_str);
// char	*get_line(char *stat_str);
// char	*wow_next_line(char *stat_str);



char	*ft_line(char *str);
char	*ft_after_line(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);

#endif