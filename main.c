#include <stdio.h>

#include "color_print.h"

int main(int argc, char **argv)
{
	color_init(0, 1);
	color_set_theme(0);
	color_printf("*aThis is the color_print *htest*a program.*d\n");
	color_free();
	return 0;
}

