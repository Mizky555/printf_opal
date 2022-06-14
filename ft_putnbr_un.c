int    ft_putnbr_un(unsigned int n)
{
        unsigned int    i;
        char    iii;
		int	len;

        i = n;
		len = 0;
       	if (i >= 10)
        {
                len += ft_putnbr(i / 10);
        }
        iii = (i % 10) + '0';
        len += write(1, &iii, 1);
		return (len);
}