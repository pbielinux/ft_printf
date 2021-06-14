#include "../include/ft_printf.h"

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
