int foo(int a, ...)
{
	return a;
}

int main()
{
	long a=1,b=2,c=3;
	foo(a,b,c);
	return 0;
}
