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
#include <stdio.h>
int main()
{
	char *p = "hello";
	char *q = "hello";
	printf("p=%p\n", p);
	printf("q=%p\n", q);
	//*p = 'a'; // runtime error
	p = "world";
	printf("p=%p\n", p);
	printf("q=%p\n", q);

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	char a[] = "hello";
	char *q = "hello";
	printf("a=%s\n", a );
	*a = 'a'; 
	printf("a=%s\n", a );
	a = "world"; // compile error

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
