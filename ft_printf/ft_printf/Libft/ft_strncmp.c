/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:58:40 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/04/25 20:31:03 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Compares the two strings
 * @param *s1 Pointer to the first string that will be compared
 * @param *s2 Pointer to the second string that will be compared
 * @param n Size of bytes that will be compared
 * @return The ascii diference of both strings
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((s1[i] != s2[i]))
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}
/*#include <stdio.h>
int	main()
{
	printf("%d\n", ft_strncmp("OLA amigos", "OLA Amigos", 5));
}*/
