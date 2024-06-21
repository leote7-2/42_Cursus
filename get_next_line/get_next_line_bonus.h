/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:08:21 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/06/21 14:20:10 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strjoin(char *str, char *buffer);
int		ft_newline(char *buffer, int i);
#endif