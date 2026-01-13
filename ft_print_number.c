/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:33:20 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 12:33:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char str[])
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_print_number(int n)
{
    int len;

    len = 0;
    if (n == 0)
        return (len + ft_print_char('0'));
    if (n == -2147483648)
        return (len + ft_print_string("-2147483648"));
    if (n < 0)
    {
        ft_print_char('-');
        n = -n;
        ft_print_number(n);
    }
    else
    {
        if (n >= 10)
            ft_print_number(n / 10);
        return (len + ft_print_char((n % 10) + '0'));
    }
}
