#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

int my_global=10;

void foo()
{
}

int main()
{
	char *func_name;
	Dl_info dlip;
	int ret;

	foo();

	ret = dladdr(&my_global, &dlip); 
	printf("ret=%d\n", ret );
	printf("%s=%p\n", dlip.dli_sname, &my_global);
	return 0;
}
