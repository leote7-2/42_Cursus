/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:00:11 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 01:00:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
    char	*str_buffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	create_list(t_list **lst, int fd);
void	add(t_list **lst, char *buffer);
char	*get_line(t_list *lst);
void	abcdef(t_list **lst);
void	free_list(t_list **lst, t_list *clean_node, char *buffer);
int		len_newline(t_list *lst);
void	copy_str(t_list *lst, char *str);
t_list	*find_last_node(t_list *lst);
int		newline(t_list *lst);

#endif
