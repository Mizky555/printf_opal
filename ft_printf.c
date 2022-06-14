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


int	ft_printf(const char *fmt,...)
{
	va_list	args;
	va_start(args, fmt);
	int	len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c')
			{
				len += ft_putchar(va_arg(args, int));
				fmt++;
			}
			else if (*(fmt + 1) == 's')
			{
				len += ft_putstr(va_arg(args, char *));
				fmt++;
			}
			else if (*(fmt + 1) == 'd' || *(fmt +1) == 'i')
			{
				len += ft_putnbr(va_arg(args, int));
				fmt++;
			}
			else if (*(fmt + 1) == 'u')
			{
				len += ft_putnbr_un(va_arg(args, unsigned int));
				fmt++;
			}
			else if (*(fmt + 1) == 'X')
			{
				len += ft_putnbr_16(va_arg(args, unsigned int));
				fmt++;
			}
			else if (*(fmt + 1) == 'x')
			{
				len += ft_putnbr_16mini(va_arg(args, unsigned int));
				fmt++;
			}
			else if (*(fmt + 1) == 'p')
			{
				len += write(1 ,"0x", 2);
				ft_putnbr_p(va_arg(args, unsigned long));
				fmt++;
			}
			else if (*(fmt + 1) == '%')
			{
				len += write(1, "%", 1);
				fmt++;
			}

		}
		else
		{
			len += ft_putchar(*fmt);
		}
		fmt++;
	}
	return (len);
}