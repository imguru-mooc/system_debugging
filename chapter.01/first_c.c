#include <stdio.h>
extern  int asm_main();

int main()
{
    int ret;
    ret = asm_main();
    printf("ret=%d\n", ret);
    return 0;
}

