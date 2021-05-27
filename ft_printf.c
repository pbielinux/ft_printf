/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:54:33 by pbielik           #+#    #+#             */
/*   Updated: 2021/05/27 17:26:20 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		count;

	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	initTab(tab);
	va_start(tab->args, format);

	i = -1;
	count = 0;
	while (format[++i]) // While the format string exists
	{
		if (format[i] == '%') // If the [i] is %
			i = parseFormat(tab, format, i + 1); // start evaluate after %, so i+1!!
		else
			count += write(1, &format[i], 1);
	}

/*  	printf("\n\nWidth: %-8d\t", flags.width);
	printf("Precision: %-8d\t", flags.precision);
	printf("Types: %-8c\t", flags.types);
	printf("Left Pads: %-8d\t", flags.leftPads);
	printf("Left Justify: %-8d\t", tab.leftJustify);
	printf("Return: %-8d\n", flags.count); */

	va_end(tab->args);
	count += tab->count;
	free(tab);
	return (count);
}

t_print	*initTab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->leftJustify = 0;
	tab->leftPads = 0;
	tab->sign = 0;
	tab->isZero = 0;
	tab->percent = 0;
	tab->count = 0;
	tab->type = 0;
	return (tab);
}

int		parseFormat(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos]) || format[pos] == '%'))
	{
/* 		if (format[pos] == '0')
			pos = parseZero(tab, format, pos);
		if (format[pos] == '*')
			pos = parseStar(tab, format, pos);
		if (format[pos] == '-')
			pos = parseDash(tab, format, pos);
		if (format[pos] == '.')
			pos = parsePrecision(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = parseWidth(tab, format, pos); */
	}
	parseVar(tab, format, pos);
	return (pos);
}

int		parseVar(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		outChar(tab);
/* 	else if (format[pos] == 's')
		outString(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		outInt(tab);
	else if (format[pos] == 'u')
		outUnsignedInt(tab);
	else if (format[pos] == 'p')
		outPointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		outHexaInt(tab, format[pos] - 23);
	else if (format[pos] == '%')
		percentage(tab); */
	return (pos);
}




/* void	printType(t_flags *flags, va_list args)
{
	if (flags->type == 'c')
	{
		if (!flags->leftJustify)
			printWidth(flags, 1, 0, 0);

		ft_putchar(va_arg(args, int), flags);

		if (flags->leftJustify)
			printWidth(flags, 1, 0, 0);
	}

	if (flags->type == 's')
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

	if (flags->type == 'd' || flags->types == 'i')
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
} */
