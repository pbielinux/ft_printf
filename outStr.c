#include "ft_printf.h"

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
	len = updateTabString(tab, str, len);
	if(!tab->leftJustify && tab->width > len)
		printRightAlpha(tab, len);
	if(tab->precision > 0)
		while (str[i] && tab->precision)
		{
			tab->count += write(1, &str[i], 1);
			i++;
			tab->precision--;
		}
	else
		while (str[i])
		{
			tab->count += write(1, &str[i], 1);
			i++;
		}
	if (str && tab->leftJustify && tab->width)
		printLeftAlpha(tab, len);
}

int		updateTabString(t_print *tab, char *str, int len)
{
	if(str)
		len = ft_strlen(str);
	if(tab->percent > 0 && len > tab->percent)
		len = tab->percent;
	return (len);
}
