#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

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

void print_gnu_backtrace(void)
{
	void *  frame_addrs[16];
	char**  frame_strings;
	size_t backtrace_size;
	int i;

	backtrace_size = backtrace( frame_addrs, 16 );
	frame_strings = backtrace_symbols( frame_addrs, backtrace_size );

	for( i=0; i<backtrace_size; ++i )
	{
		printf("%d: [0x%p] %s\n", i, frame_addrs[i], frame_strings[i] );
	}
	free( frame_strings );
}


