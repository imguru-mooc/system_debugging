#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signo)
{
	printf("sighandler(%d)\n", signo );
	exit(0);
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

int main()
{
	signal(SIGSEGV, sighandler);
	func1();
	return 0;
}
