#if 1
#include <stdio.h>
#include <unistd.h>
int main()
{
	int i;
	char str[] = "hello!";
	for(i=0; ;i++)
	{
		printf("%d : %s\n", i, str);
		sleep(1);
	}
}
#endif


