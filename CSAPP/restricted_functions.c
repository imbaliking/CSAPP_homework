#include "restricted_functions.h"

int return_1_A(int x) {
	// ! mean convert bits to logic,when all bits is 0,! return 1;when any bits contain 1,! return 0;
	return !(~x);
}
int return_1_B(int x) {
	return !(x);
}
int return_1_C(int x) {
	return !(~(x | ~(0xFF)));
}

int return_1_D(int x) {
	return !(x>>((sizeof(int)<<3)-8));
}

int int_shifts_are_arithmetic() {
	int x = -1;
	return x == (x >> 1);
}

unsigned srl(unsigned x, int k) {
	unsigned xsra = (int)x >> k;
	int w = sizeof(int) * 8;
	unsigned mask = (1 << (w-k)) - 1;
	return (unsigned)(xsra & mask);
}
int sra(int x, int k) {
	int xsrl = (unsigned)x >> k;
	int w = sizeof(int) * 8;
	int sign = !(!(x & (1 << (w - 1))));
	// when sign is 0,mask is all 0;sign is 1,mask is 1...10...0
	int mask = ((sign << k) - sign) << (w - k);
	return (int)(xsrl | mask);
}

int any_add_one(unsigned x) {
	unsigned odd_mask = 0x99999999;
	return !~((x & odd_mask)| ~odd_mask);
}

int odd_ones(unsigned x) {
	unsigned odd_mask = 0x99999999;
	return !(!(x & odd_mask));
}


