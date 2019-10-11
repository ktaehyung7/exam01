#include <stdio.h>
#include <string.h>

const int TRUE = 1;

int is_prime(int n) {
	int i;
	for(i=2; i< n; i++)
		if(n%i ==0)
			return !TRUE;
	return TRUE;
}

int main(int argc, char** argv) {
	int num;
	int result=0;

	printf("Insert num: ");
	scanf("%d", &num);

	result = is_prime(num);
	printf("\nnum is %s number.\n", result ? "prime" : "non prime");
	
	return 0;
}
