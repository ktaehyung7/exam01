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

int gcd_modulus(int u, int v) {
	int t;
	while(v) {
		t = u%v;
		u = v;
		v = t;
	}
	return u;
}

void main() {
	int num1, num2;
	int result1=0;
	int result2=0;

	printf("\nInput num1 num2: ");
	scanf("%d %d", &num1, &num2);

	result1= gcd_minus(num1, num2);
	printf("\nresult1: %d\n", result1);

	result2= gcd_modulus(num1, num2);
	printf("\nresult2: %d\n", result2);
}
