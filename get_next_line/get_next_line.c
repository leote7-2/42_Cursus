/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:39:50 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 14:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	surplus(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	int	i;
	int	j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*lst);
	i = 0;
	j = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[i] != '\n')
		++i;
	while (last_node->str_buffer[i] && last_node->str_buffer[++i])
		buffer[j++] = last_node->str_buffer[i];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	free_list(lst, clean_node, buffer);
}

char	*get_line(t_list *lst)
{
	int			str_len;
	char	*next_str;

	if (lst == NULL)
		return (NULL);
	str_len = len_newline(lst);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	str_copy(lst, next_str);
	return (next_str);
}

void	add(t_list **lst, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*lst);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL);
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **lst, int fd)
{
	int			char_read;
	char	*buffer;
	
	while(!find_newline(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add(lst, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 ||read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	next_line = get_line(lst);
	surplus(&lst);
	return (next_line);
}