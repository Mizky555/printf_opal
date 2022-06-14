int    ft_putnbr(int n)
{
        long    i;
        char    iii;
		int	len;

		len = 0;
        i = (long)n;
        if (i < 0)
        {
                len += write(1, "-", 1);
                i *= -1;
        }
        if (i >= 10)
        {
                len += ft_putnbr(i / 10);
        }
        iii = (i % 10) + '0';
        len += write(1, &iii, 1);
		return (len);
}
