/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:42:28 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/05 14:45:55 by tsirirak         ###   ########.fr       */
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

void    ft_putnbr_2(unsigned int n)
{
        unsigned int    i;
        char    iii;

        i = n;
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

void    ft_putnbr_16(unsigned int n)
{
        unsigned int    i;
        char    iii;

        i = 123;
       	if (i >= 10)
        {
			123/10 = 12 /10 = 1
            ft_putnbr(i / 10);
        }
        iii = (i % 10) + '0';
        write(1, &iii, 1);
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
			else if (*(fmt + 1) == 'd' || *(fmt +1) == 'i')
			{
				ft_putnbr(va_arg(args, int));
				fmt++;
			}
			else if (*(fmt + 1) == 'u')
			{
				ft_putnbr_2(va_arg(args, unsigned int));
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
	printf("printf 65536, -1 = %u, %u\n", 65536, -1);
	ft_printf("ft_printf 65536, -1 = %u, %u\n",65536, -1);
	return (0);
}






	
