#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#define BGGRN  "\x1B[48;5;48;38;5;0m"
#define BGYLW  "\x1B[48;5;11;38;5;0m"
#define BGMGT  "\x1B[48;5;13;38;5;0m"
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
int		ft_numLength(long n);
int		ft_numLengthBase(unsigned long n, int base);
int		ft_putnbrBase(unsigned long n, char *base);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_isspace(int c);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

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
