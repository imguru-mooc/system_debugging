#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <asm/ptrace.h>

int main(int argc, char *argv[])
{
	int pid, status, ret;
	struct user_regs_struct regs;

	if(!(pid = fork())) {
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execl( "/bin/ls" , "/bin/ls" , NULL );
		return 0;
	}
	wait(&status);
	if(WIFSIGNALED(status)) {
		fprintf(stderr, "child process %d was abnormal exit.\n", pid);
		return -1;
	}

	ret = ptrace(PTRACE_GETREGS, pid, 0, &regs);
	printf("return : %d\n", ret);
	printf("stack rsp = %p\n", (void*)regs.rsp);
	printf("rip       = %p\n", (void*)regs.rip);

	//ptrace(PTRACE_DETACH, pid, 0, 0);
	ptrace(PTRACE_KILL, pid, 0, 0);
}

