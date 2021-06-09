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

int	ft_putnbrBase(unsigned long n, char *base)
{
	unsigned int	baseLength;
	int				numLength;

	numLength = 1;
	baseLength = ft_strlen(base);
	if (n == 0)
	{
		write(1, "0", 1);
		return (numLength);
	}
	if (n >= baseLength)
	{
		numLength += ft_putnbrBase(n / baseLength, base);
		write(1, &base[n % baseLength], 1);
	}
	else if (n < baseLength)
		write(1, &base[n], 1);
	return (numLength);
}

int	ft_numLength(long n)
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

int	ft_numLengthBase(unsigned long n, int base)
{
	int count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return (count);
	}
	while(n > 0)
	{
		count++;
		n /= base;
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
	int		neg;
	size_t	len;
	char	*tab;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	neg = (n < 0) ? 1 : 0;
	n = (neg == 1) ? n * -1 : n;
	len = ft_counter(n);
	if (!(tab = (char *)malloc(sizeof(char) * len + neg + 1)))
		return (NULL);
	tab[len + neg] = '\0';
	while (len > 0)
	{
		tab[--len + neg] = n % 10 + 48;
		n /= 10;
	}
	tab[0] = neg == 1 ? '-' : tab[0];
	return (tab);
}

char	*ft_uitoa(unsigned int n)
{
	char	*a;
	int		len;

	len = ft_numLength(n);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len--] = '\0';
	if (n == 0)
		a[len] = 0 + '0';
	while (n > 0)
	{
		a[len--] = n % 10 + '0';
		n /= 10;
	}
	return (a);
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

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str) + 1;
	if (!(copy = malloc((unsigned int)len)))
		return (NULL);
	ft_memcpy(copy, str, len);
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	csrc = (char *)src;
	cdest = (char *)dest;
	if (!csrc && !cdest && n > 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
