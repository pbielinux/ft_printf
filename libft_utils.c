#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_counter(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*tab;

	if (n < 0)
		n *= -1;
	if (n == 0)
		return ("0");
	len = ft_counter(n);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	tab[len] = '\0';
	while (len > 0)
	{
		tab[--len] = n % 10 + 48;
		n /= 10;
	}
	return (tab);
}
