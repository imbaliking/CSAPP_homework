
// 复制的代码，需要做的其实是防止空引用，就是把0这个值设定好然后传给xp
// gcc优化必须O3 且tmp必须为static 才会生成条件传输的汇编码 实在是不懂
long cread(long *xp){
    static long tmp = 0;
    if (xp == 0){
        xp = &tmp;
    }
    return *xp;
}