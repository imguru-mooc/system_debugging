#include <stdio.h>

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

typedef struct layout
{
	void* rbp;
	void* rip;
} layout;

void print_gnu_backtrace()
{
	layout* bp = __builtin_frame_address(0);
	while( bp )
	{
		printf("%p\n", bp->rip );
		bp = bp->rbp;
	}
}

