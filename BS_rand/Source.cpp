#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BS_rand.h"

int main(){

	position ppos{ 1, 1 }, apos{ 1, 1 }, bpos{ 1, 1, 0 }, cpos{ 1, 1, 3 }, dpos{ 1, 1, 1 }, map_s;

	printf("Choose a map size (x and y coord): ");
	scanf_s("%d %d", &map_s.x, &map_s.y);

	ppos.x = map_s.x / 2;
	ppos.y = map_s.y / 2;

	//setting up positions

	srand(time(NULL));

	do {
		apos.x = rand() % (map_s.x - 1) + 1;
		apos.y = rand() % (map_s.y - 1) + 1;
	} while (apos.x == ppos.x && apos.y == ppos.y);

	do {
		bpos.x = rand() % (map_s.x - 3) + 2;
		bpos.y = rand() % (map_s.y - 3) + 2;
	} while (bpos.x == ppos.x && bpos.y == ppos.y || bpos.x == apos.x && bpos.y == apos.y);

	do {
		cpos.x = rand() % (map_s.x - 4) + 3;
		cpos.y = rand() % (map_s.y - 4) + 3;
	} while (cpos.x == ppos.x && cpos.y == ppos.y || cpos.x == apos.x && cpos.y == apos.y || cpos.x == bpos.x && cpos.y == bpos.y);

	do {
		dpos.x = rand() % (map_s.x - 5) + 4;
		dpos.y = rand() % (map_s.y - 5) + 4;
	} while (dpos.x == ppos.x && dpos.y == ppos.y || dpos.x == apos.x && dpos.y == apos.y || dpos.x == bpos.x && dpos.y == bpos.y || dpos.x == cpos.x && dpos.y == cpos.y);

	//setting up the board

	char** board = (char**)malloc(map_s.x * map_s.y);

	for (int i = 0; i < map_s.y; i++) {
		for (int j = 0; j < map_s.x; j++) {
			board[i][j] = ' ';
		}
	}

	board[ppos.y][ppos.x] = '@';
	board[apos.y][apos.x] = 'A';
	board[bpos.y][bpos.x] = 'B';
	board[cpos.y][cpos.x] = 'C';
	board[dpos.y][dpos.x] = 'D';

	switch (bpos.dir) {
	case 0: if (board[bpos.y][bpos.x - 1] == ' ') {
		board[bpos.y][bpos.x - 1] = 'B';
		break;
	}

	case 1: if (board[bpos.y][bpos.x + 1] == ' ') {
		board[bpos.y][bpos.x + 1] = 'B';
		break;
	}

	case 2: if (board[bpos.y + 1][bpos.x] == ' ') {
		board[bpos.y + 1][bpos.x] = 'B';
		break;
	}

	case 3: if (board[bpos.y - 1][bpos.x] == ' ') {
		board[bpos.y - 1][bpos.x] = 'B';
		break;
	}
	}

	switch (cpos.dir) {
	case 3: if (!board[cpos.y - 1][cpos.x] || !board[cpos.y - 2][cpos.x]) {
		board[cpos.y - 1][cpos.x] = board[cpos.y - 2][cpos.x] = 'C';
		break;
	}

	case 0: if (!board[cpos.y][cpos.x - 1] || !board[cpos.y][cpos.x - 2]) {
		board[cpos.y][cpos.x - 1] = board[cpos.y][cpos.x - 2] = 'C';
		break;
	}

	case 1: if (!board[cpos.y][cpos.x + 1] || !board[cpos.y][cpos.x + 2]) {
		board[cpos.y][cpos.x + 1] = board[cpos.y][cpos.x + 2] = 'C';
		break;
	}

	case 2: if (!board[cpos.y + 1][cpos.x] || !board[cpos.y + 2][cpos.x]) {
		board[cpos.y + 1][cpos.x] = board[cpos.y + 2][cpos.x] = 'C';
		break;
	}

	}

	switch (dpos.dir) {
	case 1: if (!board[dpos.y][dpos.x + 1] || !board[dpos.y][dpos.x + 2] || !board[dpos.y][dpos.x + 3]) {
		board[dpos.y][dpos.x + 1] = board[dpos.y][dpos.x + 2] = board[dpos.y][dpos.x + 3] = 'C';
		break;
	}

	case 3: if (!board[dpos.y - 1][dpos.x] || !board[dpos.y - 2][dpos.x] || !board[dpos.y - 3][dpos.x]) {
		board[dpos.y - 1][dpos.x] = board[dpos.y - 2][dpos.x] = board[dpos.y - 3][dpos.x] = 'C';
		break;
	}

	case 0: if (!board[dpos.y][dpos.x - 1] || !board[dpos.y][dpos.x - 2] || !board[dpos.y][dpos.x - 3]) {
		board[dpos.y][dpos.x - 1] = board[dpos.y][dpos.x - 2] = board[dpos.y][dpos.x - 3] = 'C';
		break;
	}

	case 2: if (!board[dpos.y + 1][dpos.x] || !board[dpos.y + 2][dpos.x] || !board[dpos.y + 3][dpos.x]) {
		board[dpos.y + 1][dpos.x] = board[dpos.y + 2][dpos.x] = board[dpos.y + 3][dpos.x] = 'C';
		break;
	}

	}

	printf("%s", board);

	getchar();
	getchar();
	return 0;
}