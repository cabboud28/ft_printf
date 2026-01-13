/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:26:26 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 16:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_unsigned(unsigned int n)
{
    int len;

    len = 0;
    if (n == 0)
        return (len + ft_print_char('0'));
    else
    {
        if (n >= 10)
            len = len + ft_print_unsigned(n / 10);
        len = len + ft_print_char((n % 10) + '0');
    }
    return (len);
}