#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
	int x, y, i, j, p=-1, d=1;
	int half_x, half_y;
	scanf("%d %d", &x, &y);

	half_x = (int)ceil(x/2);
	half_y = (int)ceil(y/2);

	for(i=0; i<x; i++) {

		if(i>= half_x || half_y < 0) d = -1;

		p += d * 2;
		half_y -= d;

		for(j=0; j<half_y+1; j++) {
			printf(" ");
		}
		for(j=0; j<p; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
