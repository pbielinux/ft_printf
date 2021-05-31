#include "ft_printf.h"

int main()
{
	printf("%s", TXBLU);
	printf("\n\t\t---------- String %%s ----------\t\n\n");

	////////////////////////////////
	printf("Just Print: \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%s\t", "Hello");
	printf("%s\t", "World");
	printf("%s\n\n", "It Works!");
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%s\t", "Hello");
	ft_printf("%s\t", "World");
	ft_printf("%s\n\n\n", "It Works!");
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Right Justify (%%15s): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%15s\t", "Hello");
	printf("%15s\t", "World");
	printf("%15s\n\n", "It Works!");
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%15s\t", "Hello");
	ft_printf("%15s\t", "World");
	ft_printf("%15s\n\n\n", "It Works!");
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Left Justify (%%-15s): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%-15s\t", "Hello");
	printf("%-15s\t", "World");
	printf("%-15s\n\n", "It Works!");
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%-15s\t", "Hello");
	ft_printf("%-15s\t", "World");
	ft_printf("%-15s\n\n\n", "It Works!");
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Precision (%%.4s): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%.4s\t", "Hello");
	printf("%.4s\t", "World");
	printf("%.4s\n\n", "It Works!");
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%.4s\t", "Hello");
	ft_printf("%.4s\t", "World");
	ft_printf("%.4s\n\n\n", "It Works!");
	ft_printf("%s", RESET);
	fflush(stdout);

	////////////////////////////////
	printf("%s", TXBLU);
	printf("Precision + Width (%%10.4s): \n\n");

	printf("%s", RESET);
	printf("%s\t", "System:   ");
	printf("%s", BGGRN);
	printf("%10.4s\t", "Hello");
	printf("%10.4s\t", "World");
	printf("%10.4s\n\n", "It Works!");
	printf("%s", RESET);
	fflush(stdout);

	ft_printf("%s\t", "My Printf:   ");
	ft_printf("%s", BGGRN);
	ft_printf("%10.4s\t", "Hello");
	ft_printf("%10.4s\t", "World");
	ft_printf("%10.4s\n\n\n", "It Works!");
	ft_printf("%s", RESET);
	fflush(stdout);
}
