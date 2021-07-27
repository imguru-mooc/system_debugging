#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>


int main(int argc, char *argv[])
{
	int ret, pid, i;

	pid = atoi(argv[1]);

	ret = ptrace(PTRACE_ATTACH, pid, 0, 0);

	printf("return : %d\n", ret);
	getchar();

	ptrace(PTRACE_DETACH, pid, 0, 0);
}

