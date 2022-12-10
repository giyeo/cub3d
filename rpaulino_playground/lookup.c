#include <math.h>
#include <stdio.h>
#include <time.h>

	// static double sins[memsized];
	// static double coss[memsized];
#define PI 3.14159265359

double	dgtorad(double i)
{
	return ( i * (PI / 180.0));
}
//stores 90 million values of cos and the same as sin.
#define sized 1000000
#define memsized 90 * sized + 1
int main()
{
	int md = sized;
	static int sins[memsized];
	static int coss[memsized];
	int i = 0;
	while (i <= (90 * md)) {
		sins[i] = (int)(sin(dgtorad((double)i / md)) * md);
		coss[i] = (int)(cos(dgtorad((double)i / md)) * md);
		i++;
	}
	printf("done\n");
	//return (sins[value * md] / md);

	// double vs, vc;
	// clock_t begin = clock();
	// for(int k = 0; k < 10000; k++)
	// {
	// 	for(int j = 0; j <= 90; j++)
	// 	{
	// 		vs = sin(j);
	// 		vc = cos(j);
	// 	}
	// }
	// clock_t end = clock();
	// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	// printf("it took calc:%f\n", time_spent);

	// begin = clock();
	// for(int k = 0; k < 10000; k++)
	// {
	// 	for(int j = 0; j <= 90; j++)
	// 	{
	// 		vs = sins[j];
	// 		vc = coss[j];
	// 	}
	// }
	// end = clock();
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// printf("it took lookup:%f\n", time_spent);
	return (0);
}
