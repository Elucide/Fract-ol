#include <math.h>
#include <stdio.h>

int main()
{
	double _Complex z = 1 + 5 * I;
	printf("%f\n", crealf(z));
	return (0);
}
