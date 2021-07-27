#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

void print_gnu_backtrace();

void bar()
{
	print_gnu_backtrace();
}

void foo()
{
	bar();
}

int main()
{
	foo();
	return 0;
}


void **save_bp;
void **getBP(int dummy)
{
	void **bp = (void**)(&dummy + 5) ;
	return bp;
}
void print_gnu_backtrace(void)
{
	int dummy=10;
	int frame = 0;
	Dl_info dlip;

	void **bp = getBP(dummy);
	void **ret = *(bp+1);
	save_bp = (void**)*bp;
	while(save_bp)
	{
		if( dladdr(ret, &dlip) == 0 )
			break;
		printf("Frame %d : [bp=%p] [ret=%p] %s\n", frame++, save_bp, ret, dlip.dli_sname );
		bp = (void**)(save_bp);
		ret = *(bp+1);
		save_bp = (void**)*bp;
	}
}

