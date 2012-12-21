int GLOBAL_DIVISIONS = 8;								//N° di suddivisioni uguali della scatola
int GLOBAL_N_PARTICLES = 512;//GLOBAL_DIVISIONS*GLOBAL_DIVISIONS*GLOBAL_DIVISIONS;		//512 <-> 8^3
int GLOBAL_ITER_TOT = 1000;								//Iterazioni totali da fare

double GLOBAL_STEP = 50.0;

double GLOBAL_L_BOX = 100;
double GLOBAL_DT = 1;									//Step simulazione in unità ridotte
double GLOBAL_PARTICLE_MASS = 1.6998e-3;						//Massa ridotta delle particelle
double GLOBAL_THETA = 5.666e-4;								//Kb*T ridotto

struct VEC_3D
{
  double x,y,z;
};

struct PARTICLE
{
  struct VEC_3D	posold;
  struct VEC_3D	pos;
  struct VEC_3D	vel;
  double mass;
};
