/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:08:24 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/06/21 14:24:21 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	str = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (ft_newline(buffer[fd], 0))
			break ;
	}
	return (str);
}