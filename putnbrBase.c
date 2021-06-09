#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbrBase(long n, char *base)
{
	int			baseLength;
	static int	numLength = 0;

	baseLength = ft_strlen(base);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		numLength += write(1, "-", 1);
	}
	if (n >= baseLength)
	{
		ft_putnbrBase(n / baseLength, base);
		numLength += write(1, &base[n % baseLength], 1);
	}
	else if (n < baseLength)
		write(1, &base[n], 1);
	return (numLength);
}

int main()
{
	printf("    %d    ", ft_putnbrBase(-1, "0123456789abcdef"));
	return (0);
}
