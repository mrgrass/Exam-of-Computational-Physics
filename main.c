#include "lib/dinamica_globali.h"

#include "lib/analisi.h"
#include "lib/potenziali.h"
#include "lib/dinamica.h"
#include "lib/montecarlo.h"

#include <stdio.h>
#include <math.h>

double Vij(double x)
{
	return potenziali_lennard(x);
}

int main(){
	struct PARTICLE sys[GLOBAL_N_PARTICLES];
	double v_quad,v_vecchio;
	int i,j,nint;
	printf("ciao\n");
	srand(time(0));
	dinamica_inizializza(sys);

	nint=5;
	v_quad=0;
	for (i=1;i<nint;i++){
		v_vecchio=potenziali_sistema(sys, Vij);
		for (j=0;j<GLOBAL_N_PARTICLES;j++){
			sys[j]=dinamica_evolvi_particle_metropolis(sys, j, Vij);
		}
		//if (i>nint/2.0){ 
			v_quad=v_quad+(potenziali_sistema(sys, Vij)-v_vecchio)*(potenziali_sistema(sys, Vij)-v_vecchio);
			printf("%g\n", v_quad/(i-nint/2));
		//}
	}
	//Potenziale quadro madio
	printf("%g\n", 2*v_quad/nint);
	return 0;
}