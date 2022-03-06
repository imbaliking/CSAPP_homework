#include "restricted_functions.h"
#include "show_bytes.h"
#include <limits.h>
#include <stdio.h>

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
	// 原理是把最高位的1不断往后移位，同时将移位后的结果和原本的结果进行或运算，可以保证最高位后面的位全都变成1
	// 只执行到16是因为unsigned 为 32位
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x & ((~x >> 1) | INT_MIN);
}


int int_size_is_32_B() {
	int set_msb = 1 << 31;
	int ret = set_msb - 1;
	return !(ret>>31);
}

int int_size_is_32_C() {
	int set_msb = 0xFFFF << 15;
	int beyond_msb = set_msb << 15;
	return !!(set_msb<<1) & (!(beyond_msb<<2));
}

int lower_one_mask(int n) {
	int ret = 1 << n;
	// 最后减掉的是当n=32位时编译器会自动循环移位把1移到开头，只能再减去1
	return ret - 1 - !!(ret &1);
}
