

struct PARTICLE dinamica_evolvi_particle_metropolis(struct PARTICLE* sys, int i, double (*Vij)(double))
{
	struct PARTICLE p,pnew;
	struct PARTICLE sysnew[GLOBAL_N_PARTICLES];
	double V, V_new;
	double probability;
	int j;

	p=sys[i];
	pnew=p;
	V=potenziali_sistema(sys,Vij);

	//for (j=1;j<GLOBAL_N_PARTICLES;j++){ sysnew[j]=sys[j];}

	sys[i].pos.x=sys[i].pos.x+((double)rand()/(double)RAND_MAX)*GLOBAL_STEP;
	sys[i].pos.y=sys[i].pos.y+((double)rand()/(double)RAND_MAX)*GLOBAL_STEP;
	sys[i].pos.z=sys[i].pos.z+((double)rand()/(double)RAND_MAX)*GLOBAL_STEP;
	sys[i].pos=dinamica_box_boundary(sys[i].pos.x, sys[i].pos.y, sys[i].pos.z);
	
	V_new=potenziali_sistema(sys,Vij);
	probability = exp((1/GLOBAL_THETA)*(V_new - V));

	if (probability>((double)rand()/(double)RAND_MAX)) {p=sys[i];} else {sys[i]=p;}
	
	//printf("%g\n", probability );

	return p;
}
