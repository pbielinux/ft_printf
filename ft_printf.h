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
	int leftJustify;
	int leftPads;
	int precision;
	int width;
	int count;
	int types;
} t_flags;

int		ft_printf(char *format, ...);
void	ft_putchar(char c, t_flags *flags);
int		parseFlags(t_flags *flags, char *format, va_list args, int i);
int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
void	printType(t_flags *flags, va_list args);
void	printWidth(t_flags *flags, int spaces, int width, int zero);
size_t	ft_strlen(const char *str);
void 	printPrecision(t_flags *flags, int len, char *str);
char	*ft_itoa(int n);
void 	printInt(t_flags *flags, int num);

#endif
