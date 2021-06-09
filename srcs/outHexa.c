#include "../ft_printf.h"

void	outHexa(t_print *tab)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(tab->args, unsigned int);
	if (!arg)
	{
		printZero(tab);
		return ;
	}
	len = ft_numLengthBase(arg, 16);
	updateTab(tab, len);
	printRightNumber(tab);
	tab->count += ft_putnbrBase(arg, "0123456789abcdef");
	printLeftNumber(tab);
}

void	outUpperHexa(t_print *tab)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(tab->args, unsigned int);
	if (!arg)
	{
		printZero(tab);
		return ;
	}
	len = ft_numLengthBase(arg, 16);
	updateTab(tab, len);
	printRightNumber(tab);
	tab->count += ft_putnbrBase(arg, "0123456789ABCDEF");
	printLeftNumber(tab);
}
