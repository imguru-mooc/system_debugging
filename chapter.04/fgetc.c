#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	int count=0;

	fp = fopen(argv[1], "r");

	while( (ch = fgetc(fp)) != EOF )
		++count;

	fclose(fp);
	printf("count=%d\n", count );

	return 0;
}
