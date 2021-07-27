#if 1
#include <stdlib.h>
int main()
{
	char *p = malloc(8192);
	return 0;
}
#endif

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	int i=0;
	fd = open("/tmp/foo",  O_RDONLY );
	if ( fd < 0 )
		i=5;
	else 
		i=2;
	return i;
}
#endif
