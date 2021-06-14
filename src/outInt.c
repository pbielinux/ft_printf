#include "../include/ft_printf.h"

void	outInt(t_print *tab)
{
	long		arg;
	char	*num;
	int		len;
	int		i;

	arg = va_arg(tab->args, int);
	if (arg == 0)
		return (printZero(tab));
	if (arg < 0)
	{
		arg *= -1;
		tab->sign = 1;
	}
	if (arg == -2147483648)
		num = "2147483648";
	else
		num = ft_itoa(arg);
	len = ft_strlen(num);
	updateTab(tab, len);
	printRightNumber(tab);
	i = 0;
	while (num[i])
		tab->count += write(1, &num[i++], 1);
	if (tab->leftJustify)
		printLeftNumber(tab);
	free(num);
}

void	outUnsignedInt(t_print *tab)
{
	unsigned int	arg;
	char			*num;
	int				len;
	int				i;

	arg = va_arg(tab->args, int);
	if (arg == 0)
		return (printZero(tab));
	num = ft_uitoa(arg);
	len = ft_strlen(num);
	updateTab(tab, len);
	printRightNumber(tab);
	i = 0;
	while (num[i])
		tab->count += write(1, &num[i++], 1);
	if (tab->leftJustify)
		printLeftNumber(tab);
	free(num);
}

void	printZero(t_print *tab)
{
	tab->isZero = 1;
	if ((tab->width && tab->leftPads) || tab->point)
		return (printRightZero(tab));
	updateTab(tab, 1);
	while (!tab->leftJustify && --tab->width > 0)
		tab->count += write(1, " ", 1);
	tab->count += write(1, "0", 1);
	while (tab->leftJustify && --tab->width > 0)
		tab->count += write(1, " ", 1);
}

void	printRightZero(t_print *tab)
{
	if (tab->width && (tab->point || tab->leftPads))
	{
		if (!tab->precision)
		{
			while (tab->leftPads && tab->width-- > 0)
				tab->count += write(1, "0", 1);
			while (!tab->leftPads && tab->width-- > 0)
				tab->count += write(1, " ", 1);
		}
		else
		{
			tab->width -= tab->precision;
			while (tab->leftJustify && tab->precision-- > 0)
				tab->count += write(1, "0", 1);
			while (tab->width-- > 0)
				tab->count += write(1, " ", 1);
			while (!tab->leftJustify && tab->precision-- > 0)
				tab->count += write(1, "0", 1);
		}
	}
	else if (tab->point)
		printZeroPoint(tab);
}

void	printZeroPoint(t_print *tab)
{
	if (tab->precision < 0)
		tab->count += write(1, "0", 1);
	while (!tab->width && tab->precision-- > 0)
		tab->count += write(1, "0", 1);
}
