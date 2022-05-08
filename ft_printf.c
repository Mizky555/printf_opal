/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:01:12 by tsirirak          #+#    #+#             */
/*   Updated: 2022/05/08 22:27:11 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     len;

    len = 0;
    if (fmt == NULL)
        return (0);
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt != '%')
        {
            // fd = file descriptor
            // 0 = stdin => for read
            // 1 = stdout (normal)
            // 2 = stderr (error)
            // etc. = opened file
            write(1, fmt, 1);
        }
        fmt++;
        len++;
    }
    va_end(ap);
    return (len);
}

int main(void)
{
    ft_printf("Hello World\n");
}