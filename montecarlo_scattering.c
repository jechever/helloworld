#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M_PI 3.14159265358979323846

/*This code generates n random scattering events for a target with atomic number Z. The target used in this simulation is a gold cylinder with radius 20cm */

int main(){
  int Z = 79;      //sample atomic number corresponding to gold 
  int E_0 = 150;   //pseudo peak energy for incident electrons in eV
  int i, n = 10000;//indices and number of events 
  int k = 10;      //spread of normal distribution z in eV 
  int rho = 17;    //density of target in g cm^-3
  int A = 196;     //atomic weight
  long N = 6*pow(10,23); //avogadro's number
  double E[n];     //incident beam energy in MeV 
  double z[n];     //pseudo-random normal distribution
  double sigma[n]; //cross section in cm^-3
  double alpha;    //screening parameter
  double random1, random2, random3, random4; //random numbers generated
  double dE /*dE/dS*/, J /*mean ionization potential*/, S /*distance travelled after scattering*/;
  double lambda /*mean free path*/, step[n] /*scattering position*/, E_s[n]/*E at scattering point*/, E_f[n]/*final E*/, psi[n], phi[n]; 
  srand(time(NULL));

   for(i=1;i<=n;i++){
     random1 = rand()/(double)RAND_MAX; //array might be needed
     random2 = rand()/(double)RAND_MAX; //array might be needed
     random3 = rand()/(double)RAND_MAX; //array might be needed
     random4 = rand()/(double)RAND_MAX; //array might be needed
     z[i-1] = (sqrt(-2*log(random1)))*(cos(2*M_PI*random2)); 
     E[i-1] = E_0*(1+k*z[i-1]);
     alpha = 3.4*pow(10,-3)*pow(Z,0.67)/E[i-1];   
     sigma[i-1] = (5.21*pow(10,-21)*Z*Z*4*M_PI*(E[i-1]+511)*(E[i-1]+511))/(E[i-1]*E[i-1]*alpha*(1+alpha)*(E[n-1]+1024)*(E[n-1]+1024));   
     lambda = A/(N*rho*sigma[i-1]); //mean free path in cm 
     step[i-1] = -lambda*log(random1);//interaction point in cm
     phi[i-1] = acos(1-((2*alpha*random3)/(1+alpha-random3)));
     psi[i-1] = 2*M_PI*random4;
     J = (9.76*Z+58.5/pow(Z,0.19))*pow(10,-3);
     dE = -78500*((rho*Z)/(A*E[i-1]))*log((1.166*E[i-1]/J)+1);
     S = 20/cos(psi[i-1]); /*by simple trigonometry the distance travelled after scattering is the radius of cylinder (20cm) divided by the cosine of azymuthal angle, which might be phi, not sure*/  
     E_s[i-1] = E[i-1]-dE*step[i-1];
     E_f[i-1] = E_s[i-1] - dE*S;
     printf("%f %f %f %f %f %f  \n", step[i-1], E[i-1], E_s[i-1], E_f[i-1], phi[i-1], psi[i-1]);
   }
  return 0;
}
