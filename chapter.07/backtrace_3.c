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
	void **bp = getBP(dummy);
	void **ret = *(bp+1);
	save_bp = (void**)*bp;
	while(save_bp)
	{
		printf("%p\n", ret );
		bp = (void**)(save_bp);
	    ret = *(bp+1);
		save_bp = (void**)*bp;
	}
}

