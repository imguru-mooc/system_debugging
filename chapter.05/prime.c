#include <stdio.h>

int main()
{
	unsigned guess;          /* current guess for prime      */
	unsigned factor;         /* possible factor of guess     */
	unsigned limit;          /* find primes up to this value */

	printf("Find primes up to: ");
	scanf("%u", &limit);

	printf("2\n");    /* treat first two primes as special case */
	printf("3\n");

	guess = 5;        /* initial guess */
	while ( guess <= limit ) {
		/* look for a factor of guess */
		factor = 3;
		while ( factor*factor < guess && guess % factor != 0 )
			factor += 2;
		if ( guess % factor != 0 )
			printf("%d\n", guess);
		guess += 2;    /* only look at odd numbers */
	}
	return 0;
}
