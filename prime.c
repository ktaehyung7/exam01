#include <stdio.h>
#include <string.h>
#include "math.h"

const int TRUE = 1;

int is_prime(int n) {
	int i;
	for(i=2; i< n; i++)
		if(n%i ==0)
			return !TRUE;
	return TRUE;
}

int is_prime2(int n) {
	int i, sqrn;
	sqrn = (int)sqrt(n);
	for(i=2; i<= sqrn; i++)
		if(n%i ==0)
			return !TRUE;
	return TRUE;
}

int main(int argc, char** argv) {
	int num;
	int result=0, result2=0;

	printf("Insert num: ");
	scanf("%d", &num);

	result = is_prime(num);
	printf("\nnum is %s number.\n", result ? "prime" : "non prime");
	
	result2 = is_prime2(num);
	printf("\nresult2: num is %s number.\n", result2 ? "prime" : "non prime");

	return 0;
}
