#include "../include/ft_printf.h"

t_print	*initTab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->point = 0;
	tab->leftJustify = 0;
	tab->leftPads = 0;
	tab->sign = 0;
	tab->isZero = 0;
	tab->percent = 0;
	tab->count = 0;
	tab->type = 0;
	return (tab);
}

t_print *resetTab(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->point = 0;
	tab->leftJustify = 0;
	tab->leftPads = 0;
	tab->sign = 0;
	tab->isZero = 0;
	tab->percent = 0;
	tab->type = 0;
	return (tab);
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
	else if (tab->precision > tab->width)
	{
		tab->width = 0;
		tab->precision -= len;
	}
}

int		updateTabString(t_print *tab, char *str, int len)
{
	if(str)
		len = ft_strlen(str);
	if(tab->precision > 0 && len > tab->precision)
		len = tab->precision;
	return (len);
}
