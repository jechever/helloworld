#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"
#define pi 3.141592653589793
#define e 2.718281828459045

//bit-scramble the input data by swaping elements

/*I get the swapping of elements, but I can't figure out 
where the imaginary input is supposed to come from.
So, I don't think I understand what any of these variables
 are, or how they relate to the previous parts of my 
program.  As such, I can't figure out which variables to 
pass in and out of the function.
*/

Bit *scramble(Bit *swap){

  Bit s;
  swap = &s;

  int count = s.count;
  double *flux = s.flux;

  int Half = count/2;
  int minus1 = count-1;

  double RealT, ImagT;
  double *RealA = NULL, *ImagA = NULL;
  //I think RealA[] might be what I call flux[], but ImagA[] should not be time[]

  int i=1, j=1, k=1;
  for(i=1; i<=minus1; i++){
    if(i<j){
      RealT = RealA[j];
      ImagT = ImagA[j];
      RealA[j] = RealA[i];
      ImagA[j] = ImagA[i];
      RealA[i] = RealT;
      ImagA[i] = ImagT;
    }
    k=Half;
    while(k<j){
      j-=k;
      k = k/2;
    }
    j+=k;
  }

  swap-> flux = flux;
  swap-> count = count;

  return swap;
}
