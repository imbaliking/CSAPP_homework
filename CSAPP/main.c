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
	unsigned x = 2;
	unsigned y = 89;

	printf("%d\n", int_size_is_32_B());
	printf("%d\n", int_size_is_32_C());
	return 0;
}
