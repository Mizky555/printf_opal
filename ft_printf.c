/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:42:28 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/04 02:17:43 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

void    ft_putstr(char *s)
{
        write(1, s, ft_strlen(s));
}

void    ft_putnbr(int n)
{
        long    i;
        char    iii;

        i = (long)n;
        if (i < 0)
        {
                write(1, "-", 1);
                i *= -1;
        }
        if (i >= 10)
        {
                ft_putnbr(i / 10);
        }
        iii = (i % 10) + '0';
        write(1, &iii, 1);
}

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int	ft_printf(const char *fmt,...)
{
	va_list	args;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c')
			{
				ft_putchar(va_arg(args, char));
				fmt++;
			}
			else if (*(fmt + 1) == 's')
			{
				ft_putstr(va_arg(args, char *));
				fmt++;
			}
		}
		else
		{
			ft_putchar(*fmt);
		}
		fmt++;
	}
	return (0);
}

int	main()
{
	ft_printf("Hello%s\n","OPAL");
	return (0);
}






	
