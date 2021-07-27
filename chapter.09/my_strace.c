#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <asm/ptrace.h>

int read_addr_into_buff(const pid_t pid, const unsigned long long addr, char * buff, unsigned int buff_size){
	unsigned int bytes_read = 0;
	long * read_addr = (long *) addr;
	long * copy_addr = (long *) buff;
	unsigned long ret;
	memset(buff, '\0', buff_size);
	do {
		ret = ptrace(PTRACE_PEEKTEXT, pid, (read_addr++), NULL);
		*(copy_addr++) = ret;
		bytes_read += sizeof(long);
	} while(ret && bytes_read < (buff_size - sizeof(long)));
	return bytes_read;
}

int main(int argc, char *argv[])
{
	int flag=0;
	int pid, status, ret;
	struct user_regs_struct regs;

	if(!(pid = fork())) {
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		execl( "/bin/ls" , "/bin/ls" , NULL );
		return 0;
	}
	while(1)
	{
		wait(&status);
	//	printf("%x\n", status );
		if(WIFSIGNALED(status)) {
			fprintf(stderr, "child %d was abnormal exit.\n", pid);
			return -1;
		}
		if(WIFEXITED(status)) {
			fprintf(stderr, "child %d was normal exit.\n", pid);
			return -1;
		}

		ret = ptrace(PTRACE_GETREGS, pid, 0, &regs);

		if( regs.orig_rax == SYS_open )
		{

			if( flag == 0 )
			{
				int i;
				char buff[256]={0,};
				read_addr_into_buff(pid, regs.rdi, buff, 256);
				printf("open(\"%s\")" , buff );
				flag = 1;
			}
			else if ( flag == 1 )
			{
				printf(" = %d\n" , (int)regs.rax );
				flag = 0;
			}
		}

		ptrace(PTRACE_SYSCALL, pid, 0, 0);
		//		getchar();
	}
}

