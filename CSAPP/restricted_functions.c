#include "restricted_functions.h"
#include <limits.h>

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

int leftmost_one(unsigned x) {
	// generate 0..01...1
	// ԭ���ǰ����λ��1����������λ��ͬʱ����λ��Ľ����ԭ���Ľ�����л����㣬���Ա�֤���λ�����λȫ�����1
	// ִֻ�е�16����Ϊunsigned Ϊ 32λ
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x & ((~x >> 1) | INT_MIN);
}


