#include "ft_printf.h"

int main()
{

	printf("%s", TXBLU);
	printf("\nprintf: ");
	printf("%s", BGGRN);
	printf(" %*.5s||%*.5s ", -10, "123", 10, "4567");
	printf("%s", RESET);
	printf("%s", TXBLU);
	printf("\nft_printf: ");
	printf("%s", BGGRN);
	fflush(stdout);
	ft_printf(" %*.5s||%*.5s ", -10, "123", 10, "4567");
}
