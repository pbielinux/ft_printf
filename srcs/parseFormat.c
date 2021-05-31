#include "../ft_printf.h"

int		parseFormat(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos]) || format[pos] == '%'))
	{
  		if (format[pos] == '0')
			pos = parseZero(tab, format, pos);
		if (format[pos] == '*')
			pos = parseStar(tab, format, pos);
		if (format[pos] == '-')
			pos = parseDash(tab, format, pos);
		if (format[pos] == '.')
			pos = parsePrecision(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = parseWidth(tab, format, pos);
	}
	parseVar(tab, format, pos);
	resetTab(tab);
	return (pos);
}

int		parseVar(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		outChar(tab);
	else if (format[pos] == 's')
		outStr(tab);
/* 	else if (format[pos] == 'd' || format[pos] == 'i')
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
