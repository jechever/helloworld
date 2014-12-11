#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"
#define pi 3.141592653589793
#define e 2.718281828459045

Pad *padding(Pad *zeros){

  int pow2=0, check=0, padNum=0, i=0;
  double timeBin = 1.;
  double *timeHold = NULL;
  double *fluxHold = NULL;
  //Why am I redeclaring things I passed into the function?
  int count;
  double *time, *flux;

  //Pad *zeros;
  Pad z;
  zeros = &z;

  count = z.count;
  time = z.time;
  flux = z.flux;

  pow2 = (int)(log((double)count)/log(2.) + 0.5); // Thus count = 2^pow2
  check = (int)(pow(2., (double)pow2) + 0.5);

  if(count == check){
    printf("Your dataset is a power of 2.\n");
  }
  else{
    printf("Your dataset is not a power of 2;\n the end of the file is padded with zeros.\n");

    padNum = check - count;
    timeBin = time[1]-time[0];

    timeHold = (double *) realloc(time, check*sizeof(double) );
    time = timeHold;
    fluxHold = (double *) realloc(flux, check*sizeof(double) );
    flux = fluxHold;

    for(i=0; i<padNum; i++){
      (time)[count+i] = time[count-1+i] + timeBin*(double)i;
      (flux)[count-1] = 0.;
    }
  }

  zeros-> time = time;
  zeros-> flux = flux;
  zeros-> count = check;
  zeros-> pow2 = pow2;

  return zeros;
}
