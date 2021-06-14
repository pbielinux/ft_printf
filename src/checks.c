#include "../include/ft_printf.h"

void	checkPrecision(t_print *tab)
{
	if (tab->precision == 0 && tab->leftPads == 1)
	{
		tab->leftPads = 0;
		tab->percent = 1;
	}
	if (tab->precision < 0)
	{
		tab->precision = 0;
		tab->point = 0;
	}
}

void	checkWidth(t_print *tab)
{
	if (tab->width < 0)
	{
		tab->width *= -1;
		tab->leftJustify = 1;
		tab->leftPads = 0;
	}
}

int	checkFlag(char c)
{
	if (c == '-' || c == '.')
		return (1);
	return (0);
}
