#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#define BGGRN  "\x1B[48;5;48;38;5;0m"
#define BGYLW  "\x1B[48;5;11;38;5;0m"
#define TXBLU  "\x1B[38;5;51m"
#define TXRED  "\x1B[38;5;196m"
#define RESET  "\x1B[0m"

# define CONVERSIONS "cspdiuxX%"

typedef struct s_flags {
	va_list	args;			// arg to print
	int		width;			//   -> Width
	int		precision;		// . -> precision
	int		leftJustify;	// - -> left justify
	int		leftPads;		// 0 -> zero padding
	int		sign;			//   -> Positive or Negative number
	int		isZero;			//   -> Is number zero
	int		percent;		//   -> %
	int 	count;			//   -> Return value
	int		point;
	int		type;
} t_print;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_numlen(long n);
int		ft_atoi(const char *s);
int		ft_isspace(int c);

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
void	writePoint(t_print *tab);
void	printRightAlpha(t_print *tab, int len);
void	printLeftAlpha(t_print *tab, int len);

#endif
