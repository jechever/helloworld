#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M_PI 3.14159265358979323846
#define Z  79      //sample atomic number corresponding to gold 
#define E_0  150   //pseudo peak energy for incident electrons in eV
#define k  10      //spread of normal distribution z in eV 
#define rho  17    //density of target in g cm^-3
#define A  196     //atomic weight
#define N  6*pow(10,23) //avogadro's number

/*This code generates n random scattering events for a target with atomic number Z. The target used in this simulation is a gold cylinder with radius 20cm */

int main(){
  int  i, n = 10000;//indices and number of events 
  double E[n]/*beam energy*/, z[n]/*normal distribution*/, sigma[n]/*cross-section*/,step[n]/*scattering position*/,lambda /*mean free path*/, E_s[n]/*E at scattering point*/, E_f[n]/*final E*/, psi[n], phi[n], alpha/*screening parameter*/, dE, J /*mean ionization potential*/, S /*distance travelled after scattering*/;  
 
  srand(time(NULL));

   for(i=1;i<=n;i++){
     z[i-1] = (sqrt(-2*log((rand()/(double)RAND_MAX))))*(cos(2*M_PI*(rand()/(double)RAND_MAX))); 
     E[i-1] = E_0*(1+k*z[i-1]);
     alpha = 3.4*pow(10,-3)*pow(Z,0.67)/E[i-1];   
     sigma[i-1] = (5.21*pow(10,-21)*Z*Z*4*M_PI*(E[i-1]+511)*(E[i-1]+511))/(E[i-1]*E[i-1]*alpha*(1+alpha)*(E[n-1]+1024)*(E[n-1]+1024));   
     lambda = A/(N*rho*sigma[i-1]); //mean free path in cm 
     step[i-1] = -lambda*log((rand()/(double)RAND_MAX));//interaction point
     phi[i-1] = acos(1-((2*alpha*(rand()/(double)RAND_MAX))/(1+alpha-(rand()/(double)RAND_MAX))));
     psi[i-1] = 2*M_PI*(rand()/(double)RAND_MAX);
     J = (9.76*Z+58.5/pow(Z,0.19))*pow(10,-3);
     dE = -78500*((rho*Z)/(A*E[i-1]))*log((1.166*E[i-1]/J)+1);
     S = 20/cos(psi[i-1]); /*by simple trigonometry the distance travelled after scattering is the radius of cylinder (20cm) divided by the cosine of azymuthal angle, which might be phi or psi, depending on convention, not sure*/  
     E_s[i-1] = E[i-1]-dE*step[i-1];
     E_f[i-1] = E_s[i-1] - dE*S;

     printf("%f %f %f %f %f %f  \n", step[i-1], E[i-1], E_s[i-1], E_f[i-1], phi[i-1], psi[i-1]);
   }
  return 0;
}
