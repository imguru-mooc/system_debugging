#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *foo(void *data)
{
	char ip[100] = "192.168.56.100";
	char sep[] = ".";
	char *p;
	p = strtok( ip , sep );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0 , sep );
		sleep(1);
	}
	return 0;
}
void *bar(void *data)
{
	char hp[100] = "010-1234-5678";
	char sep[] = "-";
	char *p;
	p = strtok( hp , sep );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0 , sep );
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, bar, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	return 0;
}

