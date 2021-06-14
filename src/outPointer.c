#include "../include/ft_printf.h"

void	outPointer(t_print *tab)
{
	unsigned long	arg;
	int				len;

	len = 2;    // start with the 0x
	arg = (unsigned long)va_arg(tab->args, void *);
	if (!arg && tab->point && tab->precision > 0)
	{
		printNullPointer(tab);
		return ;
	}
	if (!(!arg && tab->point))
		len += ft_numLengthBase(arg, 16);
	if (!tab->precision || tab->width > tab->precision)
	{
		updateTab(tab, len);
		printRightNumber(tab);
	}
	else
		tab->precision = tab->precision + 2 - len;
	tab->count += write(1, "0x", 2);
	while (tab->precision-- > 0)
		tab->count += write(1, "0", 1);
	if (!(!arg && tab->point))
		tab->count += ft_putnbrBase(arg, "0123456789abcdef");
	printLeftNumber(tab);
}

void	printNullPointer(t_print *tab)
{
	if (tab->width > tab->precision)
	{
		while (tab->width-- > (tab->precision + 2))
			tab->count += write(1, " ", 1);
	}
	tab->count += write(1, "0x", 2);
	while (tab->precision-- > 0)
		tab->count += write(1, "0", 1);
}
