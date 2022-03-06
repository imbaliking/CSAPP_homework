#include "show_bytes.h"
#include "restricted_functions.h"

//CSAPP 2.59
int generate_combine(int x, int y) {
	((byte_pointer) &y)[0] = ((byte_pointer)&x)[0];
	return y;
}

//CSAPP 2.60
unsigned replace_byte(unsigned x, int i, unsigned char b) {
	if (i > sizeof(unsigned)) {
		printf("cannot replace,because range out\n");
		return x;
	}
	byte_pointer p = (byte_pointer)&x;
	p[i] = b;
	return x;
}
int main(){
	int test_D_1 = 0xF;
	int test_D_0 = ~0;
	printf("%d", int_shifts_are_arithmetic());
	return 0;
}
