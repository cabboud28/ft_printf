/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:12:03 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 23:12:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hexa(unsigned int n, int is_upper)
{
    char *base;
    int len;

    len = 0;
    if (is_upper)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (n >= 16)
        len = len + ft_print_hexa(n / 16, is_upper);
    len = len + ft_print_char(base[n % 16]);
    return (len);
}