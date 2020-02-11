#include "ft_printf.h"

void new(t_struct *st)
{
	st->s = ft_memalloc(10);
	st->q = ft_memalloc(10);
	st->tmp = ft_memalloc(10);
	st->str = ft_memalloc(10);
	st->l = ft_memalloc(10);
	st->pr = ft_memalloc(10);
	
}

void flags(char *format,t_struct *st) 
{
	while (format[st->i] >= 32 && format[st->i] <= 48)
	{
		if(format[st->i] == '+')
			st->f_plus = 1;
		if(format[st->i] == '-')
			st->f_minus = 1;
		if(format[st->i] == ' ')
			st->f_space = 1;
		if(format[st->i] == '#')
			st->f_resh = 1;
		if(format[st->i] == '0')
			st->f_nul = width(format, st);
		st->i++;
	}
}

void ft_print(char *format, t_struct *st)
{
	st->i--;
	if (st->f_resh == 1)
		format[st->i] == 'x' ? ft_putstr("0x") : 
		(format[st->i] == 'X' ? ft_putstr("0X") :
		ft_putstr("0"));
		if (st->f_nul > 0 && st->f_minus != 1)
			null_print(st);
	ft_putstr(st->tmp);
	st->i++;
}

int    width(char *format, t_struct *st)
{
    int i;
    int j;
    char *wdht;
    i = st->i;
    j = 0;
    wdht = ft_memalloc(20);
    while (format[i] != '\0' && format[i] != '%')
    {
        if (format[i] >= 48 && format[i] <= 57)
        {
            wdht[j] = format[i];
            j++;
        }
        i++;
        if (format[i] == '.' || (format[i] > 96 && format[i] < 123) || format[i] == 'X')
            break;
    }
    st->i = st->i + j - 1;
    st->wdht = ft_atoi(wdht);
	return 1;
}

void null_print(t_struct *st)
{
	int d;

	d = st->wdht - ft_strlen(st->tmp);
	while (d-- > 0)
		ft_putchar('0');
}
