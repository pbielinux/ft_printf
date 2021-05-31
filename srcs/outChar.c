#include "../ft_printf.h"

void	outChar(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);
	updateTab(tab, 1);
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
			tab->count += write(1, " ", 1);
			tab->width--;
		}
	else
		while (!tab->leftPads && tab->width > len)
		{
			tab->count += write(1, " ", 1);
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
	while (!tab->leftPads && tab->width > len)
	{
		tab->count += write(1, " ", 1);
		tab->width--;
	}
}
