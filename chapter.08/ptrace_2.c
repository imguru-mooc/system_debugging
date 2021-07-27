#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdio.h>
#include <stdlib.h>
#include <asm/ptrace.h>

int main(int argc, char *argv[])
{
	struct user_regs_struct regs;
	unsigned int data;
	int ret, pid, i;

	pid = atoi(argv[1]);

	ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
	printf("return : %d\n", ret);
	ptrace(PTRACE_GETREGS, pid, 0, &regs);
	printf("stack = %p\n", (void*)regs.rsp);

	for(i=0; i<20; i++)
	{
		data = ptrace(PTRACE_PEEKDATA, pid, regs.rsp+i*4, 0);
		printf("%08x\n", data);
	}
	ptrace(PTRACE_DETACH, pid, 0, 0);
}

