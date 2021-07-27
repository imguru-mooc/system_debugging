#define _GNU_SOURCE
#include <stdio.h>

static void __init(void)
{
	return;
}

void mcount(void)
{
	printf("mcount()\n");
}

