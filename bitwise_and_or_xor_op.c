#include <stdio.h>

int main() {
	unsigned char num1 = 1;	/* 0000 0001 */
	unsigned char num2 = 3;	/* 0000 0011 */

	printf("%d\n", num1 & num2);	/* 0000 0001: 01 and 11 bit and -> 01 */
	printf("%d\n", num1 | num2);	/* 0000 0001: 01 and 11 bit or -> 11 */
	printf("%d\n", num1 ^ num2);	/* 0000 0001: 01 and 11 bit xor -> 10 */

	return 0;
}
