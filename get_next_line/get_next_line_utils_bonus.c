/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:08:18 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/06/21 14:20:37 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_len(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_len(str) + ft_len(buffer) + 1);
	if (!new)
		return (0);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		new[i + j] = buffer [j];
		if (buffer[j++] == '\n')
			break ;
	}
	new[i + j] = '\0';
	free (str);
	return (new);
}

int	ft_newline(char *buffer, int i)
{
	char	*b;
	char	*t;

	b = buffer;
	t = buffer;
	while (*b)
	{
		if (*b == '\n')
		{
			i = 1;
			*b++ = '\0';
			break ;
		}
		*b++ = '\0';
	}
	if (i == 1)
	{
		while (*b)
		{
			*t++ = *b;
			*b++ = '\0';
		}
	}
	return (i);
}