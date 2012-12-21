#include <stdlib.h>

#define GAUSS_N_ITER 12 //12 per avere sigma=1



//numeri random gaussiani con varianza = 1 (tra +-12)
double vario_rnd_gauss()
{

	long int c;
	double s=0;

	
	for (c=0;c<GAUSS_N_ITER;c++) s+=((double)rand()/(double)RAND_MAX);
	
	s-=(double)(GAUSS_N_ITER)/2.0;
	return s;
}
