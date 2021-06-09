#include "../ft_printf.h"

void	outPercent(t_print *tab)
{
	while (tab->leftPads && !tab->leftJustify && --tab->width > 0)
		tab->count += write(1, "0", 1);
	while (!tab->leftJustify && --tab->width > 0)
		tab->count += write(1, " ", 1);
	tab->count += write(1, "%", 1);
	while (tab->leftJustify && --tab->width > 0)
		tab->count += write(1, " ", 1);
}
