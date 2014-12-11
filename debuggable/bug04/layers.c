#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"
#define pi 3.141592653589793
#define e 2.718281828459045

/*
Again, not understaning half the variables makes it difficult
 to interpret which should be passed around.
*/


Loop *layers(Loop *onion){

  Loop o;
  onion = &o;

  int count = o.count;
  int pow2 = o.pow2;
  double *flux = o.flux;

  int ke, ke1, k, ip, j, i;
  double RealU, ImagU, RealW, ImagW, angle, temp;
  double *RealA = NULL, *ImagA = NULL;
  double RealT, ImagT;


  for(k=1; k<=pow2; k++){
    ke = (int)(pow(2.,(double)k) + 0.5);
    ke1 = ke/2;

    RealU = 1.;
    ImagU = 0.;
    angle = -pi/ke1;
    RealW = cos(angle);
    ImagW = sin(angle);

    for(j=1; j<=ke1; j++){
      for(i=j; i<=count; i+=ke){
        ip = i + ke1;

        RealT = RealA[ip]*RealU - ImagA[ip]*ImagU; //T=A(ip)*U
        ImagT = RealA[ip]*ImagU + ImagA[ip]*RealU;

        RealA[ip] = RealA[i]-RealT;
        ImagA[ip] = ImagA[i]-ImagT; //A(ip) = A(i) -T
        RealA[i] += RealT;
        ImagA[i] += ImagT;       //A(i) = A(i) + T
      }
    temp = RealU*RealW - ImagU*ImagW;
    ImagU = RealU*ImagW + ImagU+RealW;     //U = U * W
    RealU = temp;
    }
  }

  onion-> flux = flux;
  onion-> count = count;
  onion-> pow2 = pow2;

  return onion;
}
