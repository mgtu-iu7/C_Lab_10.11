//Find-a-square game

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

bool next_try() {
	const char Key0 = '0', Key1 = '1';
	int loop(1);
	char ch('\0');
	printf ("\n0 - Exit, 1 - Play\n");
	printf ("\nWhat's your choice?");
	while (loop) {
		ch = _getch();
		if((ch == Key0) || (ch == Key1))
			loop--;
	}
	return ch != Key0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int xt, yt, xs, ys;//t - try, s - square
	float h(0.0), t(0.0), s(0.0);//h - number of hits, t - number of tries, s - hit statistics
	srand((unsigned)time(0));
	
	while(next_try()) {

		xs = rand()%8;
		ys = rand()%8;

		printf("\n\nEnter x:\n");
		scanf("%d", &xt);

		printf("\nEnter y:\n");
		scanf("%d", &yt);

	if ((xt == xs || xt == xs+1 || xt == xs+2) && (yt == ys || yt == ys+1 || yt == ys+2)) {
		printf("\nYou've hit the target");
		h++;
		t++;
	}
	else {
		printf("\nYou've missed");
		t++;
	}

	s = h / t;
	printf("\nHit statistics: %.3f\n", s);
	}

	_getch();
	return 0;
}
