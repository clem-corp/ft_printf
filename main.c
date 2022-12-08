#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *c;
	c = HEXALOWER;
	printf("%c\n", c[1]);
	return (0);
}