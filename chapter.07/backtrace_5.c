#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <libunwind.h>

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

void print_gnu_backtrace (void) {
	char name[256];

	unw_word_t pc, sp, offp;
	unw_cursor_t cursor;
	unw_context_t uc;
	int frame = 0;

	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);

	do {
		name[0] = '\0';
		unw_get_proc_name(&cursor, name, 256, &offp);
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		unw_get_reg(&cursor, UNW_REG_SP, &sp);
		printf("Frame %d : [bp=%p] [ret=%p] %s\n", frame++,
				(void*)sp, (void*)pc, name);
	} while (unw_step(&cursor) > 0) ;
}


