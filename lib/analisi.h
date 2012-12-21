#include <math.h>

//=====================================================================================================================
// PROTOTIPI
//=====================================================================================================================
//double analisi_deriva_primo[10]; //= {1, 8, 0, 0, 0, 0, 0, 0, 0, 0}; 			//coefficienti ricorsivi

//double analisi_deriva_coefficienti[5];// = {2, 12, 0, 0, 0}; 				//coefficienti del denominatore della funzione F(E)

double analisi_zeri_bisez(double x1, double x2, double precision, double (*f)(double));	//metodo della bisezione

double analisi_zeri_sec(double x1, double x2, double precision, double (*f)(double)); 	//metodo della secante

double analisi_integra_simpson(double x1, double x2, int N, double (*f)(double));	//integrale col metodo simpson

double analisi_deriva_trepunti(double x, double h, double (*f)(double));		//derivazione a 3 punti



//=====================================================================================================================
// DEFINIZIONI
//=====================================================================================================================

//===============metodo della bisezione=====================================
double analisi_zeri_bisez(double x1, double x2, double precision, double (*f)(double))
{
	double y1,y2,x3,y3;

	y1=f(x1);
	y2=f(x2);
	
	do {
		x3=x1+((x2-x1)/2.0);
		y3=f(x3);
		if (y1*y3>0) {x1=x3; y1=y3;} else {x2=x3; y2=y3;};
	}while(fabs(y3)>precision || y3<0);

	return x3;
}

//===============metodo della secante=======================================
double analisi_zeri_sec(double x1, double x2, double precision, double (*f)(double))
{
	double y1,y2,x3,y3;

	y1=f(x1);
	y2=f(x2);
	
	do {
		x3=x1-(y1*(x2-x1)/(y2-y1));
		y3=f(x3);
		if (y1*y3>0) {x1=x3; y1=y3;} else {x2=x3; y2=y3;};
		//printf("%.16f\t",y3);
	}while(fabs(y3)>precision);

	return x3;
}; 

//===============integrale col metodo simpson===============================
double analisi_integra_simpson(double x1, double x2, int N, double (*f)(double))
{
	double h; //passo
	double I;
	int c;

	h=fabs(x2-x1)/N;
	I=f(x1) + f(x2);

	for (c=1; c<N; c++)
		I+=(2.0+2.0*(c % 2))*(f(x1+h*c));

	return (I*h/3);
}

//===============metodo di derivazione a 3 punti============================
double analisi_deriva_trepunti(double x, double h, double (*f)(double))
{
	return 4.0*(6.0/(x*x*x*x*x*x*x)-12.0/(x*x*x*x*x*x*x*x*x*x*x*x*x)); //hacked
	//return (( f(x+h) - f(x-h) ) / (2.0*h) );
}




