#include "ft_printf.h"

int main()
{
	printf("---------- Character %%c ----------\t\n\n");
	printf("printf:\t\t%c    %c   %c   %c    %c   %c   %c    %c   %c\n\n", 'a', 'b', 'c', '0', '1', '2', '-', '+', '%');
	ft_printf("ft_printf:\t%c    %c   %c   %c    %c   %c   %c    %c   %c\n", 'a', 'b', 'c', '0', '1', '2', '-', '+', '%');
}