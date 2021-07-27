#if 1
#include <stdio.h>
#include <unistd.h>
int main()
{
	char str[] = "hello!";
	while(1)
	{
		printf("%s\n", str);
		sleep(1);
	}
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
int main()
{
	while(1)
	{
		printf("hello!\n");
		sleep(1);
	}
}
#endif

