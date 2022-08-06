
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	// char	i = 'Y';
	// char	m = 'S';
	//int		k = -1;
	//int		c;
	int		c1;
	//char *p = "this is a pointer";
	//char	str[] = NULL;

	// k = 180789565;
	// i = 'Y';
	// m = 'S';
	// c = printf("this %c and %X, now %% then come to %s and %c\n", i, k, str, m);
	// c1 = ft_printf("this %c and %X, now %% then come to %s and %c\n", i, k, str, m);
	// printf("%u\n", -20);
	// ft_printf("%u\n", -20);
	// printf ("original is %d, mine is %d\n", c, c1);

	//c = printf("%x\n", LONG_MAX);
	c1 = ft_printf("%x\n", LONG_MAX);
	//printf ("original is %d, mine is %d\n", c, c1);
	//printf ("original is %d\n",c);
	return(0);
}
//gcc -Wall -Wextra -Werror mainpf.c -L. libftprintf.a  -o myp && ./myp