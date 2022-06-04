/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <tsirirak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:01:12 by tsirirak          #+#    #+#             */
/*   Updated: 2022/05/08 23:42:38 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_printf(const char *fmt, ...)
{
    va_list va_list_ap;
    int     len;
    int     fmt_len;
    char    *string_recieved;
    char    *malloc_string;

    len = 0;
    fmt_len = 0;
    if (fmt == NULL)
        return (0);
    va_start(va_list_ap, fmt);
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
            len++;
        }
        else //*fmt == '%'
        {
            if (*(fmt+1) == '%')
            {
                write(1, "%", 1);
                len++;
            }
            if (*(fmt+1) == 's')
            {
                string_recieved = va_arg(va_list_ap, char *);
                fmt_len = strlen(string_recieved);
                // malloc_string = (char *)malloc(sizeof(char) * (fmt_len + 1));
                // malloc_string = strncpy(malloc_string, string_recieved, fmt_len);
                // malloc_string[fmt_len] = '\0';
                write(1, string_recieved, fmt_len);
                len += fmt_len;
                fmt++;
            }
        }
        fmt++;
    }
    va_end(va_list_ap);
    return (len);
}

int main(void)
{
    ft_printf("Hello %% World %% |%s|\n", "This is from %s");
    // printf("+42 = %+5d", 42);
}

// %[flags => "-+ #0"][width][.precision]specifier
/*
{
    - is_left
    + is_signed
}
*/