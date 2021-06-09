#include "../ft_printf.h"

int	parseZero(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	tab->leftPads = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numLength(i);
	}
	tab->width = i;
	return(pos);
}

int	parseDash(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->leftJustify == 1)
	{
		while (format[pos] == '-' || format[pos] == '0')
			pos++;
		return (pos);
	}
	tab->leftJustify = 1;
	tab->leftPads = 0;
	while (format[pos] == '-' || format[pos] == '0')
		pos++;
	pos = parseWidth(tab, format, pos);
	return (pos);
}

int	parsePrecision(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	tab->point = 1;
	if (ft_isalpha(format[pos]) || format[pos] == '%')
		checkPrecision(tab);
	while (format[pos] == '0' || checkFlag(format[pos]))
	{
		pos++;
		checkPrecision(tab);
	}
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numLength(i);
	}
	tab->precision = i;
	if (format[pos] == '*')
		pos = parseStar(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return(pos);
}

int	parseWidth(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	if (ft_isdigit(format[pos]))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numLength(i);
	}
	tab->width = i;
	if (format[pos] == '.')
		pos = parsePrecision(tab, format, pos);
	return (pos);
}

int	parseStar(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->point == 0)
	{
		tab->width = va_arg(tab->args, int);
		checkWidth(tab); // If the arg is Neg, have to turn on the LeftJustify and make the wdt positive.
	}
	else
	{
		tab->precision = va_arg(tab->args, int);
		checkPrecision(tab);
	}
	if (format[pos] == '.')
		pos = parsePrecision(tab, format, pos);
	if (format[pos] == '*')
		pos = parseStar(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}
