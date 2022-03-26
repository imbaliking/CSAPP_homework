#include<stdint.h>

typedef __int128 int128_t;

// 测试128位乘法，可以编译，但是不能链接，Windows和Linux的gcc编译出来结果不一样
void store_prod(int128_t *dest,int64_t x,int64_t y){
    *dest = x*(int128_t)y;
}

