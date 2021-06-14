/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:54:33 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 19:47:28 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		count;

	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	initTab(tab);
	va_start(tab->args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = parseFormat(tab, format, i + 1);
		else
			count += write(1, &format[i], 1);
	}
	va_end(tab->args);
	count += tab->count;
	free(tab);
	return (count);
}
