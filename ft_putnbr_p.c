int	ft_putnbr_p(unsigned long n)
{
	    unsigned long    i;
        char    iii;
		int	len;

		i = n;
		len = 0;
       	if (i > 15)
        {
			len += ft_putnbr_16(i / 16);
        }
		if ((i % 16 >= 10) && (i % 16 <= 15))
		{
			iii = (i % 16) + 'A' - 10;
		}
		else if ((i % 16 >= 0) && (i % 16 <= 9))
		{
			iii = (i % 16) + '0';
		}
        len += write(1, &iii, 1);
		return (len);
}
