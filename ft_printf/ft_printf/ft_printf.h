/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:39 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/05/07 17:29:58 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *format, ...);
static void		print_format(char specifier, va_list ap, long int *n);
void			print_char(int c, long int *n);
void			print_str(char *str, long int *n);
void			print_nbr(long int num, long int *n);
void			print_ptr(unsigned long int ptr, long int *n);
void			print_hex(unsigned int num, int up, long int *n);

#endif