/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:54:33 by pbielik           #+#    #+#             */
/*   Updated: 2021/05/27 15:23:35 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list args;
	//t_flags flags;
	va_start(args, format);
	int i;

	t_flags flags = {0, 0, -1, 0, 0, 0};
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = parseFlags(&flags, format, args, i);
			printType(&flags, args);
		}
		else
		{
			ft_putchar(format[i], &flags);
		}
		i++;
	}
/* 	printf("\n\nWidth: %-8d\t", flags.width);
	printf("Precision: %-8d\t", flags.precision);
	printf("Types: %-8c\t", flags.types);
	printf("Left Pads: %-8d\t", flags.leftPads);
	printf("Left Justify: %-8d\t", flags.leftJustify);
	printf("Return: %-8d\n", flags.count); */

	va_end(args);
	return (flags.count);
}

int parseFlags(t_flags *flags, char *format, va_list args, int i)
{
	while (format[i])
	{
		if (format[i] == '-') {
			flags->leftJustify = 1;
			flags->leftPads = 0;
		}
		if (format[i] == '0' && flags->leftJustify == 0 && flags->width == 0)
			flags->leftPads = 1;
		if (format[i] == '*'){
			flags->width = va_arg(args, int);
			if (flags->width < 0)
			{
				flags->width = flags->width * -1;
				flags->leftJustify = 1;
			}
		}
		if (format[i] == '.'){
			flags->precision = 0;
			i++;
			if (format[i] == '*') {
				flags->precision = va_arg(args, int);
			}
			while (ft_isdigit(format[i]))
			{
				flags->precision = flags->precision * 10 + format[i] - 48;
				i++;
			}
		}
		if (ft_isdigit(format[i]))
			flags->width = flags->width * 10 + format[i] - 48;
		if (ft_strchr(CONVERSIONS, format[i]))
		{
			flags->types = format[i];
			break;
		}
		i++;
	}
	return (i);
}

void	printType(t_flags *flags, va_list args)
{
	if (flags->types == 'c')
	{
		if (!flags->leftJustify)
			printWidth(flags, 1, 0, 0);

		ft_putchar(va_arg(args, int), flags);

		if (flags->leftJustify)
			printWidth(flags, 1, 0, 0);
	}

	if (flags->types == 's')
	{
		char *str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		if (flags->precision > (int)ft_strlen(str) || flags->precision <= -1)
			flags->precision = (int)ft_strlen(str);

		if (!flags->leftJustify)
			printWidth(flags, flags->precision, flags->width, 0);

		printPrecision(flags, flags->precision, str);

		if (flags->leftJustify)
			printWidth(flags, flags->precision, flags->width, 0);
	}

	if (flags->types == 'd' || flags->types == 'i')
	{
		printInt(flags, va_arg(args, int));

	}
}

void printInt(t_flags *flags, int num)
{
	char *str = ft_itoa(num);
	int neg = 0;

	if (num < 0)
		neg = 1;

	if (flags->leftPads && flags->precision == -1)
	{
		printWidth(flags, (int)ft_strlen(str), flags->width - neg, 1);
		if (neg)
			ft_putchar('-', flags);
		printPrecision(flags, (int)ft_strlen(str), str);
	}
	else if (!flags->leftJustify)
	{
		if (flags->precision > (int)ft_strlen(str))
			printWidth(flags, flags->precision, flags->width - neg, 0);
		else
			printWidth(flags, (int)ft_strlen(str), flags->width - neg, 0);
		if (neg)
			ft_putchar('-', flags);
		printWidth(flags, (int)ft_strlen(str), flags->precision, 1);
		printPrecision(flags, ft_strlen(str), str);
	}
	else if (flags->leftJustify)
	{
		if (neg)
			ft_putchar('-', flags);
		printWidth(flags, (int)ft_strlen(str), flags->precision, 1);
		printPrecision(flags, ft_strlen(str), str);
		if (flags->precision > (int)ft_strlen(str))
			printWidth(flags, flags->precision, flags->width - neg, 0);
		else
			printWidth(flags, (int)ft_strlen(str), flags->width - neg, 0);
	}

}

void	printWidth(t_flags *flags, int spaces, int width, int zero)
{
	int size;

	size = width - spaces;
	while (size > 0){
		if (zero)
			ft_putchar('0', flags);
		else
			ft_putchar('.', flags);
		size--;
	}
}

void printPrecision(t_flags *flags, int len, char *str)
{
	int i;

	i = 0;
	while (i < len) {
		ft_putchar(str[i], flags);
		i++;
	}
}
