#include <stdio.h>

#include "color_print.h"

int main(int argc, char **argv)
{
	color_init(0, 1);
	color_set_theme(0);
	color_printf("*aThis is the color_print *htest*a program.*d\n");
	color_printf("Here is a option list: *c[13]hi hi*d\n");
	color_printf("GS colors:\n");
	for (int i = 1; i <= 15; ++i) {
		color_printf(fmtbld("GS color %d: *c[%d]a really nice color. *d  *c[0]*g[%d]looks good in inverse too.*d\n", i, i, i));
	}
	color_printf("*dDoing it manually, here is *c[1]red,*d here is *c[7]baby blue,*d here is *c[14]aquamarine.*d\n");
	color_printf("Here is a *hcool*d blend: %s\n", color_rgb_blend("The quick brown fox jumped over the lazy dog so many times that the dog got absolutely sick of it.", 255, 255, 0, 255, 0, 255, 0));
	color_printf("Here is a *hcool*d blend: %s\n", color_rgb_blend("It was the best of times, it was the worst of times. Who wrote these words originally? I forget. Long time ago.", 0, 255, 0, 0, 128, 255, 0));
	color_printf("Here is a *hcool*d blend: %s\n", color_rgb_blend("The quick brown fox jumped over the lazy dog so many times that the dog got absolutely sick of it.", 255, 0, 0, 128, 0, 255, 0));
	color_printf("Just a colored bar: %s\n", color_rgb_blend("                            ", 0, 255, 255, 255, 255, 0, 1));
	color_printf("All 256 colors:\n");
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 8; ++j) {
			color_printf(fmtbld("*2[%d]##%03d##*d ", (i * 8) + j, (i * 8) + j));
		}
		printf("  ");
		for (int j = 0; j < 8; ++j) {
			color_printf(fmtbld("*2[0]*3[%d]  %03d  *d ", (i * 8) + j, (i * 8) + j));
		}
		printf("\n");
	}
	printf("\n");
	for (unsigned int r = 0; r <= 0xff; r += 51) {
		for (unsigned int g = 0; g <= 0xff; g += 51) {
			for (unsigned int b = 0; b <= 0xff; b += 51) {
				color_printf("%s##*d", color_rgb(r, g, b));
			}
		}
		printf(" ");
		for (unsigned int g = 0; g <= 0xff; g += 51) {
			for (unsigned int b = 0; b <= 0xff; b += 51) {
				color_printf("%s  *d", color_rgb_bg(r, g, b));
			}
		}
		printf("\n");
	}

	color_free();
	return 0;
}

