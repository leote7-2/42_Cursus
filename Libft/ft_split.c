/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:50:12 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/04/25 20:32:17 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief returns an array of str by splitting 's' by the delimiter 'c'
 * @param *s The string to be split
 * @param c The delimiter Character
 * @return The array of new strings resulting from the split
*/
static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	if (!s[b])
		return (0);
	while (s[b])
	{
		while (s[b] == c)
			b++;
		if (s[b])
			i++;
		while (s[b] != c && s[b])
			b++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**split;
	int		i;

	i = 0;
	split = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, len);
			s = s + len;
		}
	}
	split[i] = NULL;
	return (split);
}
/*
void	print_split_result(char **result)
{
	if (result == NULL)
	{
		printf("Erro: Nulo\n");
		return;
	}

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
	}
}

int	main()
{
	const char *str = "  tripouille  42  ";
	char delimiter = ' ';
	size_t count = ft_count(str, delimiter);
	printf("Número de tokens: %zu\n", count);

	char **split_result = ft_split(str, delimiter);
	printf("Resultado de ft_split:\n");
	print_split_result(split_result);

	for (int i = 0; split_result[i] != NULL; i++)
	{
		free(split_result[i]);
	}
	free(split_result);
	return 0;
}*/
/*
Objetivo: Separar a string em multiplas strings
*/
