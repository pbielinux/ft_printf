#include "ft_printf.h"

int main()
{

	printf("%s", TXBLU);
	printf("\nprintf: ");
	printf("%s", BGGRN);
	printf("\t%s\t", "Hello");
	printf("\t%s\t", "World!");
	printf("\t%s\n", "It works!");
	printf("%s", RESET);
	printf("%s", TXBLU);
	printf("\nft_printf: ");
	printf("%s", BGGRN);
	fflush(stdout);
	ft_printf("\t%s\t", "Hello");
	ft_printf("\t%s\t", "World!");
	ft_printf("\t%s\n", "It works!");
}
