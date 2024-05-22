/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:52:01 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 14:52:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (lst->str_buffer[i] == '\n')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *lst)
{
	if (lst == NULL)
		return(NULL);
	while (lst->next)
		lst =lst->next;
	return (lst);
}

void	copy_str(t_list *lst, char *str)
{
	int	i;
	int	j;
	
	if (lst == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buffer[i])
		{
			if (lst->str_buffer[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;			
			}
			str[j++] = lst->str_buffer[i++];
		}
		lst = lst->next;
	}
	str[j] = '\0';
}

int	len_newline(t_list *lst)
{
	int	i;
	int	n;
	
	if (lst == NULL)
		return (0);
	n = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buffer[i])
		{
			if (lst->str_buffer[i] == '\n')
			{
				++n;
				return (n);
			}
			++i;
			++n;
		}
		lst = lst->next;
	}
	return (n);
}

void	free_list(t_list **lst, t_list *clean_node, char *buffer)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str_buffer);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	if (clean_node->str_buffer[0])
		*lst = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}
