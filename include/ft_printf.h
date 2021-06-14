#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include "../libft/include/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags {
	va_list	args;
	int		width;
	int		precision;
	int		leftJustify;
	int		leftPads;
	int		sign;
	int		isZero;
	int		percent;
	int 	count;
	int		point;
	int		type;
} t_print;

int		ft_printf(const char *format, ...);

t_print	*initTab(t_print *tab);
t_print *resetTab(t_print *tab);
void	updateTab(t_print *tab, int len);
int		updateTabString(t_print *tab, char *str, int len);
int		parseFormat(t_print *tab, const char *format, int );

int		parseVar(t_print *tab, const char *format, int pos);
int		parseZero(t_print *tab, const char *format, int pos);
int		parseStar(t_print *tab, const char *format, int pos);
int		parseDash(t_print *tab, const char *format, int pos);
int		parsePrecision(t_print *tab, const char *format, int pos);
int		parseWidth(t_print *tab, const char *format, int pos);

void	checkPrecision(t_print *tab);
int		checkFlag(char c);
void	checkWidth(t_print *tab);

void	outChar(t_print *tab);
void	outStr(t_print *tab);
void	outInt(t_print *tab);
void	outUnsignedInt(t_print *tab);
void	outPointer(t_print *tab);
void	outHexa(t_print *tab);
void	outUpperHexa(t_print *tab);
void	outPercent(t_print *tab);
void	printNullPointer(t_print *tab);
void	printBlanks(t_print *tab);
void	printZero(t_print *tab);
void	printRightAlpha(t_print *tab, int len);
void	printLeftAlpha(t_print *tab, int len);
void	printLeftNumber(t_print *tab);
void	printRightNumber(t_print *tab);
void	printRightZero(t_print *tab);
void	printZeroPoint(t_print *tab);

#endif
