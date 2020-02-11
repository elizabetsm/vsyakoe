#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"


typedef struct				s_struct{

	char					*s; //Вывод для спецификатора s
	int						a; //int и меньше. Флаги hh, h. Спецификаторы d, i.
    long long int 			d; //Флаги l, ll для d,i.
	unsigned long long int	o; //Флаги l, ll для uoxX
	unsigned int 			u; //Охуенно логично что это для спецификатора u
	char					c; // Вывод для спецификатора c
	char					*q; //Вроде нужен для itoa
	int						i; //Счетчик
	char					*tmp;
	char					*str;
	char					*l;
	int						f;
	char					*pr;
	int						f_plus; 
	int						f_minus;
	int						f_space;
	int						f_resh;
	int						f_nul;
	int						wdht;
}							t_struct;

int 						ft_printf(char *format, ...);
int							octal(unsigned long long int a, t_struct *st);
void						new(t_struct *st);
char						*itoa(long long int a);
void						check_flags(char *format, t_struct *st, va_list ap);
void						chifr(char *format, t_struct *st, va_list ap);
int							hexadecimal(long long int a, int trig, t_struct *st);
void						specif_di(t_struct *st, long long int a);
void						specif_uoxX(t_struct *st, char *format, unsigned long long int a);
void						length(char *format, t_struct *st, va_list ap);
void						flags(char *format, t_struct *st);
void						ft_print(char *format, t_struct *st);
int							width(char *format, t_struct *st);
void						null_print(t_struct *st);
int							ft_length(long long int n);

#endif