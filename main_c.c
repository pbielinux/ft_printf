#include "ft_printf.h"

int main()
{
	printf("%s", TXBLU);
	printf("\n\t\t---------- Character %%c ----------\t\n\n");

	////////////////////////////////
	printf("Just Print: \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%c\t", 'a');
	printf("%c\t", 'b');
	printf("%c\n\n", 'c');
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%c\t", 'a');
	ft_printf("%c\t", 'b');
	ft_printf("%c\n\n\n", 'c');
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Right Justify (%%10c): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%10c\t", 'a');
	printf("%10c\t", 'b');
	printf("%10c\n\n", 'c');
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%10c\t", 'a');
	ft_printf("%10c\t", 'b');
	ft_printf("%10c\n\n\n", 'c');
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Left Justify (%%-10c): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%-10c\t", 'a');
	printf("%-10c\t", 'b');
	printf("%-10c\n\n", 'c');
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%-10c\t", 'a');
	ft_printf("%-10c\t", 'b');
	ft_printf("%-10c\n\n\n", 'c');
	ft_printf("%s", RESET);
	fflush(stdout);
}
