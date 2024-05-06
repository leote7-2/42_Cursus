/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:53 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/05/06 18:30:14 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int	print_char(int c)
{
	write(1, &c, 1);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_ptr(va_arg(ap, unsigned long long))
	else if (specifier == 'd')
		count += print_nbr(va_arg(ap, int));
	else if (specifier == 'i')
		count += print_nbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;
	
	va_start(ap, format);
	count = 0;
	while (*format != 0)
	{
		if (*format == '%')
			count += prt_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}