#include "ft_printf.h"
#include "limits.h"

int main()
{
	printf("|| %d ||", printf("\n\t%%"));
	fflush(stdout);
	ft_printf("|| %d ||", ft_printf("\n\t%%"));
}
