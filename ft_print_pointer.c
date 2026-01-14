/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:31:46 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 23:31:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_print_hexa_long(unsigned long n)
{
    char *base;
    int len;

    len = 0;
    base = "0123456789abcdef";
    if (n >= 16)
        len = len + ft_print_hexa_long(n / 16);
    len = len + ft_print_char(base[n % 16]);
    return (len);
}

int ft_print_pointer(void *ptr)
{
    int len;

    len = 0;
    if (!ptr)
        return (len + ft_print_string("(nil)")); //if pointer is NULL print (nil) not 0x0 (address = 0)
    len = len + ft_print_string("0x"); //pointer start with 0x
    len = len + ft_print_hexa_long((unsigned long)ptr);
    return (len);
}