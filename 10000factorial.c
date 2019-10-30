#include <stdio.h>

int mult(int big[], int n) {
	int i;
	for(i=1; i<=big[0]; i++) big[i] = n*big[i];
	for(i=1; i<=big[0]; i++) {
		big[i+1] = big[i+1] + big[i]/10000;
		big[i] = big[i] % 10000;
	}
	if(big[i]) big[0] = i;
/* printf("%d %d %d %d\n", big[0], big[1], big[2], big[3]); */
}

int main() {
	int i, n;
	int fac[10001] = {1,1,0,};

	printf("number: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++) mult(fac, i);
	printf("%4d", fac[fac[0]]);

	for(i=fac[0]-1; i>0; i--) printf("%04d", fac[i]);
	printf(" ##%d", fac[0]);

	return 0;
}
