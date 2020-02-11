#include "ft_printf.h"

int     ft_length(long long int n)
{
    int    i;
    i = 1;
    if (n < 0)
    {
        n = n * (-1);
        i++;
    }
    while ((n / 10) > 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

char         *itoa(long long int n)
{
    char   *a;
    int       len;
    long long int       tmp;
//    if (n == -9223372036854775808)
//        return (ft_strdup("-9223372036854775808"));
    len = ft_length(n);
    tmp = n;
    if (!(a = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    if (n == 0)
        a[0] = '0';
    if (n < 0)
    {
        a[0] = '-';
        n = n * (-1);
    }
    a[len] = '\0';
    while (n > 0)
    {
        len--;
        a[len] = (n % 10) + '0';
        n = n / 10;
    }
    return (a);
}


int	ft_printf(char *format, ...) //сюда нужно вставить остальные флаги и ширину
{
	va_list ap;
	t_struct *st;

	st = (t_struct *)malloc(sizeof(t_struct));
	// new(st);
	va_start(ap, format);
    st->i = 0;
	while (format[st->i] != '\0')
	{
		if (format[st->i] == '%')
		{
            st->i++;
		    if (format[st->i] == '%')
            {
                ft_putchar('%');
                st->i++;
            }
            flags(format, st);
            length(format, st, ap);
            //check_flags(format, st, ap);
            if (format[st->i] == 's')
            {
                st->s = va_arg(ap, char *);
                ft_putstr(st->s);
                st->i++;
            }
            else if (format[st->i] == 'c')
            {
                st->c = va_arg(ap, int);
                ft_putchar(st->c);
                st->i++;
            }
            else if (format[st->i] == 'd' || format[st->i] == 'i')
            {
                st->a = va_arg(ap, int);
                specif_di(st, st->a);
            }
            else if (format[st->i] == 'o' || format[st->i] == 'u' || format[st->i] == 'x' || format[st->i] == 'X')
            {
                unsigned int d = va_arg(ap, unsigned int);
                specif_uoxX(st, format, d);
            }
            if (format[st->i] == 'p')
            {
                st->d = va_arg(ap, long long int);
				hexadecimal(st->d, 0, st);
                ft_putstr("0x");
			    ft_putstr(st->tmp);
                st->i++;
            }
            ft_print(format, st);
        }
		else
		{
		    ft_putchar(format[st->i]);
		    st->i++;
		}
	}
	va_end(ap);
	return 0;
}

int main()
{
    // int *b;
    // int a = 0x10d;
    // b = &a;
    printf("%010u\n", 1000);
    ft_printf("%010u\n", 1000);

    return 0;
}
