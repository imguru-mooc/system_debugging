#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int a(void);
int b(void);
int c(void);

int a(void){
	return b() - 1;
}

int b(void){
	return c() + 1;
}

int c(void){
	return getpid() % 100000;
}
int main(int argc, char *argv[])
{
	int ret = 0;

	if (argc > 1)
		ret = atoi(argv[1]);

	printf("%d\n", getpid());
	ret += a();
	return ret ? 0 : 1;
}

