/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 03:15:19 by marvin            #+#    #+#             */
/*   Updated: 2026/01/13 03:15:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_string(char *str)
{
    int len;

    len = 0;
    if (!str)
        str = "(null)";
    while(str[len])
    {
        ft_print_char(str[len]);
        len++;
    }
    return (len);
}