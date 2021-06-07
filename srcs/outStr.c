#include "../ft_printf.h"

void	outStr(t_print *tab)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	str = va_arg(tab->args, char *);
	if(!str)
		str = "(null)";
	if (str && tab->point == 1 && tab->precision == 0)
		return (printBlanks(tab));
	len = updateTabString(tab, str, len);
	if(!tab->leftJustify && tab->width > len)
		printRightAlpha(tab, len);
	if(tab->precision > 0)
		while (str[i] && tab->precision--)
			tab->count += write(1, &str[i++], 1);
	else
		while (str[i])
			tab->count += write(1, &str[i++], 1);
	if (str && tab->leftJustify && tab->width)
		printLeftAlpha(tab, len);
}

void	printBlanks(t_print *tab)
{
	updateTabString(tab, NULL, 0);
	while (tab->width)
	{
		tab->count += write(1, " ", 1);
		tab->width--;
	}
}
