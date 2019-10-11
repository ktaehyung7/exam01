#include <stdio.h>

int gcd_minus(int u, int v) {
	int i;
	while(u) {
		if(u<v)
			v = u;
		u=u-v;
	}
	return v;
}

void main() {
	int result=0;

	result = gcd_minus(12, 6);
	printf("\nresult: %d\n", result);

}
