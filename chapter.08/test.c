#if 0
#include <stdio.h>
int main()
{
	char *p = "hello";
	printf("sizeof(p)=%lu\n", sizeof(p));
	printf("sizeof(\"hello\")=%lu\n", sizeof("hello"));
	printf("p=%s\n", p);
	printf("p=%s\n", "hello");
	return 0;
}
#endif

#if 0
int main()
{
	char *p = "hello";
	char *q = "hello";
	*p = 'a'; // error
	p = "world";

	return 0;
}
#endif

#if 0
int main()
{
	char a[] = "hello";
	char *q = "hello";
	*a = 'a'; 
	a = "world"; // error

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	printf("%s\n", "hello");

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i;
	for(i=0;  "hello"[i] ; i++ )
		putchar("hello"[i]);
	           //*("hello"+i)
	   	       //*(0x1000+i)

    putchar('\n');
	return 0;
}
#endif

#if 1
#include <stdio.h>
int main()
{
	int i;
	for(i=0;  i["hello"] ; i++ )
		putchar( i["hello"] );
	           // *(i + "hello")
		       // *( i + 0x1000)

	putchar('\n');
	return 0;
}
#endif
