#include "ft_printf.h"

void	outChar(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);

	if (tab->width && !tab->leftJustify)
		printRightAlpha(tab, 0);
	tab->count += write(1, &a, 1);
	if (tab->width && tab->leftJustify)
		printLeftAlpha(tab, 0);
}

void	printRightAlpha(t_print *tab, int len)
{
	while (tab->leftPads && tab->width > len)
	{
		tab->count += write(1, "0", 1);
		tab->width--;
	}
	if (!tab->leftPads && tab->precision && tab->precision < len)
		while (tab->width > tab->precision)
		{
			tab->count += write(1, ".", 1);
			tab->width--;
		}
	else
		while (!tab->leftPads && tab->width > len)
		{
			tab->count += write(1, ".", 1);
			tab->width--;
		}
}

void printLeftAlpha(t_print *tab, int len)
{
	while (tab->leftPads && tab->width > len)
	{
		tab->count += write(1, "0", 1);
		tab->width--;
	}
		while (tab->leftPads && tab->width > len)
	{
		tab->count += write(1, ".", 1);
		tab->width--;
	}
}

void	updateTab(t_print *tab, int len)
{
	if (tab->sign)
	{
		if (tab->width)
			tab->width -= 1;
	}
	if (tab->precision > 0)
		tab->leftPads = 0;
	if (tab->width && tab->width >= tab->precision)
	{
		if (tab->precision > len)
			tab->precision -= len;
		else
			tab->precision = 0;
		if (!tab->isZero)
			tab->width = tab->width - tab->precision - len;
	}
}
