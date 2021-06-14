#include "./include/ft_printf.h"
#include <limits.h>

int main(){

	printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	fflush(stdout);
	ft_printf("\n --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
}
