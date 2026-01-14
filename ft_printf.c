/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 02:22:11 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 02:22:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static because this function is only used in this file
static int ft_format_conversion(char c, va_list args)//i send the char that define the format and the va_list to get what to work with
{
    //handle each case here
    if (c == '%')
        return (ft_print_char('%'));
    else if (c == 'c')
        return (ft_print_char(va_arg(args, int))); //don't use char with va_arg (search about it)
    else if (c == 's')
        return (ft_print_string(va_arg(args, char *)));
    else if (c == 'p')
        return (ft_print_pointer(va_arg(args, void *)));
    else if (c == 'd' || c == 'i')
        return (ft_print_number(va_arg(args, int)));
    else if (c == 'u')
        return (ft_print_unsigned(va_arg(args, unsigned int)));
    else if (c == 'x')
        return (ft_print_hexa(va_arg(args, unsigned int), 0));
    else if (c == 'X')
        return (ft_print_hexa(va_arg(args, unsigned int), 1));
    else
        return (0);
}


int ft_printf(const char * format, ...)
{
    va_list args;
    int len;

    len = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;//i have to go to the next index to know the format
            len = len + ft_format_conversion(*format, args);
        }
        else
            len = len + ft_print_char(*format);
        format++;
    }
    va_end(args);
    return (len);
}
