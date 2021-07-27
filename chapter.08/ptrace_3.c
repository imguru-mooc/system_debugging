#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <asm/ptrace.h>

int main(int argc, char *argv[])
{
	struct user_regs_struct regs;
	unsigned int data;
	unsigned char data2[4];
	int ret, pid, i, j;

	pid = atoi(argv[1]);

	ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
	printf("return : %d\n", ret);
	ptrace(PTRACE_GETREGS, pid, 0, &regs);
	printf("stack = %p\n", (void*)regs.rsp);
	for(i=0; i<300; i++)
	{
		data = ptrace(PTRACE_PEEKDATA, pid, regs.rsp+i*4, 0);
		memcpy(data2, &data, 4 );
		printf("%08x : ", (unsigned int)regs.rsp+i*4);
		for(j=0; j<4; j++){
			if(isprint(data2[j]))
				printf("%c ", data2[j]);
			else
				printf(". ");
		}
		printf("%08x\n", data);
	}
	ptrace(PTRACE_POKEDATA, pid, 0x7ffe190ff240, 0x41414141);
	ptrace(PTRACE_DETACH, pid, 0, 0);
}


