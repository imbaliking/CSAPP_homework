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
	int x = -1;
	unsigned y = (unsigned)x;
	show_int(x);
	show_int(sra(x, 2));
	show_unsigned(y);
	show_unsigned(srl(y, 2));

	printf("%d\t%d\n", sra(x,2),x>>2);
	printf("%u\t%u\n", srl(y,2),y>>2);
	return 0;
}
