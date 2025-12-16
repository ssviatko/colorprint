#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#include "color_print.h"

#define BOARD_H 80
#define BOARD_V 60

uint8_t board[BOARD_V][BOARD_H];

void display_board()
{
	printf("\033[%dA\r", (BOARD_V / 2) + 1);
	for (int v = 0; v < BOARD_V; v += 2) {
		for (int h = 0; h < BOARD_H; ++h) {
			color_printf("*2[%d]*3[%d]\u2580*d", board[v][h], board[v + 1][h]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	struct timespec ts;
	ts.tv_nsec = 80000000;
	ts.tv_sec = 0;

	printf("Movement - An RGB text/graphics demonstration\n");

	// make some space
	for (int i = 0; i < (BOARD_V / 2) + 1; ++i)
		printf("\n");

	// fill board with crap
	for (int j = 0; j < 2048; ++j) {
		for (int v = 0; v < BOARD_V; ++v) {
			for (int h = 0; h < BOARD_H; ++h) {
				board[v][h] = j + (v * BOARD_V) + h;
			}
		}
		display_board();
		color_printf("\033[0mj value: %d\n", j);
		nanosleep(&ts, NULL);
	}
	color_printf("\033[0mback to normal\n");
	return 0;
}

