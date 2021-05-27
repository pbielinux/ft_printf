#include "ft_printf.h"

int main()
{
	printf("%s", TXBLU);
	printf("---------- String %%s ----------\t\n\n");

	printf("printf:\t\t%s   %15s   %-15s\n\n", "Hello World", "Hello World", "Hello World");
	ft_printf("ft_printf:\t%s   %15s   %-15s\n\n", "Hello World", "Hello World", "Hello World");


}
