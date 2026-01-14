/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:08:59 by marvin            #+#    #+#             */
/*   Updated: 2025/12/30 20:08:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int ft_print_char(int c); //va_arg types 
int ft_print_string(char *str);
int ft_print_pointer(void *ptr);
int ft_print_number(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hexa(unsigned int n, int is_upper);

#endif
