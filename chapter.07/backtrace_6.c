#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <libunwind.h>
#include <signal.h>

void sighandler(int sig){
	char name[256];
	unw_word_t pc, sp, offp;
	unw_cursor_t cursor;
	unw_context_t uc;
	int i = 0;
	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);
	unw_step(&cursor);
	while (unw_step(&cursor) > 0) {
		name[0] = '\0';
		unw_get_proc_name(&cursor, name, 256, &offp);
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		unw_get_reg(&cursor, UNW_REG_SP, &sp);
		printf("%d: %s (+0x%lx) pc = 0x%lx, sp = 0x%lx\n", i, name, (long) offp, (long) pc, (long) sp);
		i++;
	}
	exit(1);
}

void func2()
{
	int *p = (int*)-1;
	printf("%d\n", *p);
}

void func1()
{
	func2();
}

int main(int argc, char **argv)
{
	signal(SIGSEGV, sighandler);
	func1();

	return 0;
}

