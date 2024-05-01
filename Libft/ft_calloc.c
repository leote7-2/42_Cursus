/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:38:34 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/04/25 18:50:17 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Allocates a quantity of memories and initializes with zeros
 * @param num Number of elements to allocate
 * @param size Size of every element in bytes
 * @return A pointer to ptr;
*/
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((num * size) / num != size)
		return (NULL);
	ptr = (void *)malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (num * size));
	return (ptr);
}

/*int	main()
{
	size_t	num_elements = 5;
	size_t	element_size = sizeof(int);
	size_t	i = 0;
	size_t	a = 0;
	int	*array = (int *)ft_calloc(num_elements, element_size);

	if (array == NULL)
	{
		printf("Falha ao alocar memória\n");
		return 1;
	}
	while (a < num_elements)
	{
		array[a] = a * 2;
		a++;
	}
	printf("Valores do array:\n");
	while (i < num_elements)
	{	
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	free(array);
	return (0);
}*/
