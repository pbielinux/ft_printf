#include "../ft_printf.h"

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

int	ft_numlen(long n)
{
	int count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while(n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
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

int		ft_atoi(const char *s)
{
	int		sign;
	int		r;
	int		flag;

	r = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		flag++;
		s++;
	}
	if (flag > 1)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (r * sign);
}

int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
