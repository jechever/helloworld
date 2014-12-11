#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"
#define pi 3.141592653589793
#define e 2.718281828459045

int main(int argc, char* argv[]){
  FILE *input;
  input = fopen(argv[1], "r");

  int count=0;
  //, pow2=0;

  double timeIn;
  double *time = malloc(sizeof(double));
  double *timeHold = NULL;

  double fluxIn;
  double *flux = malloc(sizeof(double));
  double *fluxHold = NULL;


  //read in a 2 column file of arbitrary size
  //count the rows, and store each column in an array
  while (EOF != fscanf (input, "%lf %lf", &timeIn, &fluxIn)){
    ++count;
    timeHold = (double *) realloc(time, count*sizeof(double) );
    fluxHold = (double *) realloc(flux, count*sizeof(double) );
    
    if (NULL == timeHold || NULL == fluxHold){
      printf("error reading file\n");
      exit(EXIT_FAILURE);
    }

    time = timeHold;
    (time)[count-1] = timeIn;

    flux = fluxHold;
    (flux)[count-1] = fluxIn;
  }

  Pad *zeros;
  Pad z;
  zeros = &z;

  //call the length of file/pad with zeros subroutine
  zeros = padding(zeros);

  Bit *swap;
  Bit s;
  swap = &s;

  //call the bit-scramble subroutine
  swap = scramble(swap);

  Loop *onion;
  Loop o;
  onion = &o;

  //call loop over layers
  onion = layers(onion);

  //I feel like I should write something to a file, then have gnuplot plot it in log-log, but since I don't know what to write to the file other than 1./time[], that seems kind of pointless.

  free(time);
  free(flux);
  return 0;
}
