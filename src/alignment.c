#include "../include/ft_printf.h"

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

void	printRightNumber(t_print *tab)
{
	if (tab->sign && (tab->leftPads || tab->leftJustify ||
		(!tab->width && !tab->precision)))
	{
		tab->count += write(1, "-", 1);
		tab->sign = 0;
	}
	if (!tab->leftJustify)
	{
		while (!tab->leftPads && tab->width-- > 0)
			tab->count += write(1, " ",1);
		while (tab->leftPads && tab->width-- > 0)
			tab->count += write(1, "0",1);
		if (tab->sign)
			tab->count += write(1, "-", 1);

	}
	while (tab->precision-- > 0)
		tab->count += write(1, "0", 1);
}

void	printLeftNumber(t_print *tab)
{
	while (tab->leftPads && tab->precision-- > 0)
		tab->count += write(1, "0", 1);
	while (tab->width-- > 0)
		tab->count += write(1, " ", 1);
}
