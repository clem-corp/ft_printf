#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int c;
	c = 1565;
	printf("%x\n", c);
	ft_printf("%x\n", c);
	return (0);
}