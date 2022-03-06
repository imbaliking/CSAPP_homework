#pragma once

#define U_MAX 0xFFFFFFFF

//2.61
int return_1_A(int x);
int return_1_B(int x);
int return_1_C(int x);
int return_1_D(int x);

//2.62
int int_shifts_are_arithmetic();

//2.63
unsigned srl(unsigned x, int k);
int sra(int x, int k);

//2.64
// Return 1 when any odd bit of x equals 1;0 otherwise. Assume w=32.
int any_add_one(unsigned x);

//2.65
// Return 1 when x contains an odd number of 1s;0 otherwise.Assume w=32.
int odd_ones(unsigned x);

//2.66
//Generate mask indicating leftmost 1 in x. Assume w=32.
int leftmost_one(unsigned x);

//2.67
int int_size_is_32_B();
int int_size_is_32_C();
