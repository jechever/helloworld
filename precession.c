#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m_e 5.9736*pow(10,24)      //mass of the Earth
#define m_s  1.9891*pow(10,30)     //mass of the Sun
#define a  149598261.0             //Semi-major axis
#define e  0.0167112303531389      //Eccentricity 
#define G  6.67428*pow(10,-11)     //Newton's constant
#define KE ((G*m_e*m_s)/a)*((1/(1+e))-0.5)

double function(double x, double v, double t, double d);
double (*func)(double x, double v, double t, double d);

double function(double x, double v, double t, double d){
  return (G*m_s/pow(d,3))*x; // integrand.
}

double functiony(double y, double vy, double t, double d);
double (*funcy)(double y, double vy, double t, double d);

double functiony(double y, double vy, double t, double d){
  return (G*m_s/pow(d,3))*y; // integrand.
}

double rkn4(double (*func)(double x, double v, double t),
	    double x[], double x0, double v[], double v0, double (*funcy)(double y, double vy, double t), double y[], double y0, double vy[], double vy0, double t, double h, double d, long steps);



int main (){
	long steps = 10000000; 	       	//Number of steps.
	double x0=a,v0=0.,t,h=0.000001; //Initial position, initial velocity in x, time, step size.
	double y0=0.,vy0=sqrt((2*KE)/(m_e*(1+m_e/m_s)));//Initial position and  velocity in y-axis

	double *x = malloc(steps * sizeof(double)); 	//Position array
        double *v = malloc(steps * sizeof(double)); 	//Velocity array

	double *y = malloc(steps * sizeof(double)); 	//Position array
        double *vy = malloc(steps * sizeof(double)); 	//Velocity array
/* Set pointer to point at the function to integrate. */

	double d;

	func = function;
	funcy = functiony;

/* Do integration. */
	rkn4(func,x,x0,v,v0,funcy,y,y0,vy,vy0,t,h,d,steps);
	
/* Print results to STDOUT */
	long int i;
        for ( i=0; i<steps; ++i){
	  printf(" %d %lf %lf %lf %lf \n",i,x[i],v[i],y[i],vy[i]);
        }


	return 0;
}

double rkn4(double (*func)(double x, double v, double t), 
	    double x[], double x0, double v[],double v0, double (*funcy)(double y, double vy, double t), double y[], double y0, double vy[],double vy0, double t, double h, double d, long steps)
{
	double k1,k2,k3,k4;
	double ky1,ky2,ky3,ky4;
	

	x[0] = x0; //Initial position
	y[0] = y0;

	v[0] = v0; //Initial velocity
	vy[0] = vy0;	

	long i;
	for ( i=1; i<steps; ++i){
		k1 = func(x[i-1],v[i-1],t);	
		k2 = func(x[i-1]+h*v[i-1]/2.+h*h*k1/8.,v[i-1]+h*k1/2.,t+h/2.);
                k3 = func(x[i-1]+h*v[i-1]/2.+h*h*k1/8.,v[i-1]+h*k2/2.,t+h/2.);
		k4 = func(x[i-1]+h*v[i-1]+h*h*k3/2.,v[i-1]+h*k3,t+h);
		
		x[i] = x[i-1] + h*v[i-1] + h*h*(k1+k2+k3)/6.;
		v[i] = v[i-1] + h*(k1 + 2.*k2 + 2.*k3 + k4)/6.;

		ky1 = func(y[i-1],vy[i-1],t);	
		ky2 = func(y[i-1]+h*vy[i-1]/2.+h*h*ky1/8.,vy[i-1]+h*ky1/2.,t+h/2.);
                ky3 = func(y[i-1]+h*vy[i-1]/2.+h*h*ky1/8.,vy[i-1]+h*ky2/2.,t+h/2.);
		ky4 = func(y[i-1]+h*vy[i-1]+h*h*ky3/2.,vy[i-1]+h*ky3,t+h);
		
		y[i] = y[i-1] + h*vy[i-1] + h*h*(ky1+ky2+ky3)/6.;
		vy[i] = vy[i-1] + h*(ky1 + 2.*ky2 + 2.*ky3 + ky4)/6.;

		d = pow((x[i-1]*x[i-1]+y[i-1]*y[i-1]),0.5);
		t+=h;
	}
	
	return 0;
}
